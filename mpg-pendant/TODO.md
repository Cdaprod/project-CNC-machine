You’ve defined the right first version: the Nano becomes a **USB-serial MPG pendant interface**. It reads the handwheel, six-axis selector, increment selector, rapid button, and E-stop state; the PC or Raspberry Pi translates those events into machine-specific motion commands.

The classic Nano cannot become native USB HID because its ATmega328P communicates through a CH340/FTDI USB-serial converter. That’s fine here—USB serial is exactly what the original MPG-Nano/UCCNC design uses. Wi-Fi or Bluetooth can later be added at the Raspberry Pi layer without rewriting the pendant firmware.

The original project is now archived and only implements four axes, so this sketch preserves its `R`/`S` protocol while adding axes 5 and 6 plus a readable JSON command. The protocol behavior comes directly from the [original MPG-Nano repository](https://github.com/mattbucknall/mpg-nano) and its [serial implementation](https://github.com/mattbucknall/mpg-nano/blob/master/app-serial.c).

## Important E-stop boundary

The Nano can **report** that E-stop was pressed, but USB software must never be the only E-stop path.

The E-stop’s safety contacts should eventually interrupt the controller-enable circuit, safety relay, spindle-enable chain, or machine drive-enable input directly. The Nano receives a parallel sensing contact or auxiliary contact.

## Firmware commands

| Command | Response | Purpose |
|—|—|—|
| `S` | `[Sxxxxxx]` | Original UCCNC-compatible status |
| `R` | `[R]` | Clear accumulated handwheel movement |
| `J` | JSON object | Easy integration with Raspberry Pi |
| `V` | Identification string | Confirm firmware/version |

`S` and `J` both consume the accumulated encoder movement, meaning the next request starts counting from zero.

## Create the firmware using Terminal

`~/Arduino/cdaprod-mpg-nano/cdaprod-mpg-nano.ino`

```bash
mkdir -p ~/Arduino/cdaprod-mpg-nano
nano ~/Arduino/cdaprod-mpg-nano/cdaprod-mpg-nano.ino
```

Paste this entire sketch:

`~/Arduino/cdaprod-mpg-nano/cdaprod-mpg-nano.ino`

```cpp
#include <Arduino.h>

// ——————————————————————————
// CDAProd six-axis MPG Nano
//
// USB serial protocol:
//   R -> [R]
//   S -> [Sddddss]
//        dddd = signed 16-bit encoder delta as hexadecimal
//        ss   = switch/status byte
//   J -> JSON status line
//   V -> firmware identification
//
// Serial configuration: 38400 baud, 8-N-1
// ——————————————————————————

constexpr uint32_t SERIAL_BAUD = 38400;

// Step-size selector
constexpr uint8_t PIN_STEP_X1   = 2;
constexpr uint8_t PIN_STEP_X10  = 3;
constexpr uint8_t PIN_STEP_X100 = 4;

// Pendant indicators and controls
constexpr uint8_t PIN_PENDANT_LED = 5;
constexpr uint8_t PIN_ESTOP       = 6;
constexpr uint8_t PIN_RAPID       = 7;

// Axis selector
constexpr uint8_t PIN_AXIS_Z = 8;
constexpr uint8_t PIN_AXIS_4 = 9;
constexpr uint8_t PIN_AXIS_5 = 10;
constexpr uint8_t PIN_AXIS_6 = 11;
constexpr uint8_t PIN_AXIS_X = A4;
constexpr uint8_t PIN_AXIS_Y = A5;

// Handwheel encoder
constexpr uint8_t PIN_ENCODER_A_POS = A0;
constexpr uint8_t PIN_ENCODER_A_NEG = A1;
constexpr uint8_t PIN_ENCODER_B_POS = A2;
constexpr uint8_t PIN_ENCODER_B_NEG = A3;

enum Axis : uint8_t {
  AXIS_OFF = 0,
  AXIS_X   = 1,
  AXIS_Y   = 2,
  AXIS_Z   = 3,
  AXIS_4   = 4,
  AXIS_5   = 5,
  AXIS_6   = 6
};

enum StepSelection : uint8_t {
  STEP_X1    = 0,
  STEP_X10   = 1,
  STEP_X100  = 2,
  STEP_X1000 = 3
};

// Each complete quadrature cycle becomes one MPG count.
int16_t encoderDelta = 0;
int8_t encoderSubsteps = 0;

// Previous encoder state stored in bits 3:2.
uint8_t previousEncoderState = 0;

bool pendantLedState = false;
bool nanoLedState = false;

uint32_t lastPendantLedChange = 0;
uint32_t lastNanoLedChange = 0;

// Quadrature transition table based on the decoder used by MPG-Nano.
constexpr int8_t QUADRATURE_TABLE[16] = {
   0,  1, -1,  0,
  -1,  0,  0,  1,
   1,  0,  0, -1,
   0, -1,  1,  0
};

uint8_t readEncoderState() {
  uint8_t state = 0;

  if (digitalRead(PIN_ENCODER_A_POS) == HIGH) {
    state |= 0x01;
  }

  if (digitalRead(PIN_ENCODER_B_POS) == HIGH) {
    state |= 0x02;
  }

  return state;
}

void pollEncoder() {
  const uint8_t currentState = readEncoderState();
  const uint8_t transitionIndex =
      previousEncoderState | currentState;

  const int8_t movement =
      QUADRATURE_TABLE[transitionIndex];

  previousEncoderState = currentState << 2;

  if (movement == 0) {
    return;
  }

  encoderSubsteps += movement;

  if (encoderSubsteps >= 4) {
    encoderDelta++;
    encoderSubsteps -= 4;
  } else if (encoderSubsteps <= -4) {
    encoderDelta—;
    encoderSubsteps += 4;
  }
}

int16_t takeEncoderDelta() {
  const int16_t capturedDelta = encoderDelta;

  encoderDelta = 0;

  return capturedDelta;
}

void resetEncoder() {
  encoderDelta = 0;
  encoderSubsteps = 0;
  previousEncoderState = readEncoderState() << 2;
}

Axis readAxis() {
  // Axis selector contacts are active-low because the pendant’s switch
  // common is connected to ground.

  if (digitalRead(PIN_AXIS_X) == LOW) {
    return AXIS_X;
  }

  if (digitalRead(PIN_AXIS_Y) == LOW) {
    return AXIS_Y;
  }

  if (digitalRead(PIN_AXIS_Z) == LOW) {
    return AXIS_Z;
  }

  if (digitalRead(PIN_AXIS_4) == LOW) {
    return AXIS_4;
  }

  if (digitalRead(PIN_AXIS_5) == LOW) {
    return AXIS_5;
  }

  if (digitalRead(PIN_AXIS_6) == LOW) {
    return AXIS_6;
  }

  return AXIS_OFF;
}

StepSelection readStepSelection() {
  // Rapid has highest priority.
  if (digitalRead(PIN_RAPID) == LOW) {
    return STEP_X1000;
  }

  if (digitalRead(PIN_STEP_X100) == LOW) {
    return STEP_X100;
  }

  if (digitalRead(PIN_STEP_X10) == LOW) {
    return STEP_X10;
  }

  // x1 is also the safe default if no increment contact is detected.
  return STEP_X1;
}

bool readEStop() {
  // This preserves the original MPG-Nano behavior:
  // normal closed contact = LOW
  // opened/pressed/disconnected contact = HIGH
  return digitalRead(PIN_ESTOP) == HIGH;
}

const char* axisName(Axis axis) {
  switch (axis) {
    case AXIS_X:
      return “X”;

    case AXIS_Y:
      return “Y”;

    case AXIS_Z:
      return “Z”;

    case AXIS_4:
      return “4”;

    case AXIS_5:
      return “5”;

    case AXIS_6:
      return “6”;

    default:
      return “OFF”;
  }
}

uint16_t stepMultiplier(StepSelection step) {
  switch (step) {
    case STEP_X10:
      return 10;

    case STEP_X100:
      return 100;

    case STEP_X1000:
      return 1000;

    default:
      return 1;
  }
}

uint8_t buildSwitchByte(
    Axis axis,
    StepSelection step,
    bool eStop
) {
  uint8_t status = static_cast<uint8_t>(axis) & 0x07;

  status |=
      (static_cast<uint8_t>(step) & 0x03) << 3;

  if (eStop) {
    status |= 1 << 5;
  }

  return status;
}

void sendLegacyStatus() {
  const int16_t delta = takeEncoderDelta();
  const Axis axis = readAxis();
  const StepSelection step = readStepSelection();
  const bool eStop = readEStop();

  const uint8_t switchByte =
      buildSwitchByte(axis, step, eStop);

  char response[12];

  snprintf(
      response,
      sizeof(response),
      “[S%04X%02X]\r\n”,
      static_cast<uint16_t>(delta),
      switchByte
  );

  Serial.print(response);
}

void sendJsonStatus() {
  const int16_t delta = takeEncoderDelta();
  const Axis axis = readAxis();
  const StepSelection step = readStepSelection();
  const bool eStop = readEStop();

  Serial.print(F(“{\”device\”:\”cdaprod-mpg-nano\””));
  Serial.print(F(“,\”axis\”:\””));
  Serial.print(axisName(axis));
  Serial.print(F(“\””));
  Serial.print(F(“,\”axis_id\”:”));
  Serial.print(static_cast<uint8_t>(axis));
  Serial.print(F(“,\”step\”:”));
  Serial.print(stepMultiplier(step));
  Serial.print(F(“,\”step_id\”:”));
  Serial.print(static_cast<uint8_t>(step));
  Serial.print(F(“,\”delta\”:”));
  Serial.print(delta);
  Serial.print(F(“,\”estop\”:”));
  Serial.print(eStop ? F(“true”) : F(“false”));
  Serial.println(F(“}”));
}

void processSerialCommands() {
  while (Serial.available() > 0) {
    char command = static_cast<char>(Serial.read());

    if (command >= ‘a’ && command <= ‘z’) {
      command -= ‘a’ - ‘A’;
    }

    switch (command) {
      case ‘R’:
        resetEncoder();
        Serial.print(F(“[R]\r\n”));
        break;

      case ‘S’:
        sendLegacyStatus();
        break;

      case ‘J’:
        sendJsonStatus();
        break;

      case ‘V’:
        Serial.print(
            F(“[V,CDAPROD-MPG-NANO,1.0.0,6AXIS]\r\n”)
        );
        break;

      default:
        // Ignore line endings and unsupported characters.
        break;
    }
  }
}

void updatePendantLed() {
  const Axis axis = readAxis();
  const StepSelection step = readStepSelection();

  if (axis == AXIS_OFF) {
    pendantLedState = false;
    digitalWrite(PIN_PENDANT_LED, LOW);
    return;
  }

  const uint32_t interval =
      step == STEP_X1000 ? 125UL : 500UL;

  const uint32_t now = millis();

  if (now - lastPendantLedChange >= interval) {
    lastPendantLedChange = now;
    pendantLedState = !pendantLedState;

    digitalWrite(
        PIN_PENDANT_LED,
        pendantLedState ? HIGH : LOW
    );
  }
}

void updateNanoLed() {
  const uint32_t now = millis();

  if (now - lastNanoLedChange >= 500UL) {
    lastNanoLedChange = now;
    nanoLedState = !nanoLedState;

    digitalWrite(
        LED_BUILTIN,
        nanoLedState ? HIGH : LOW
    );
  }
}

void configurePins() {
  pinMode(PIN_STEP_X1, INPUT_PULLUP);
  pinMode(PIN_STEP_X10, INPUT_PULLUP);
  pinMode(PIN_STEP_X100, INPUT_PULLUP);

  pinMode(PIN_ESTOP, INPUT_PULLUP);
  pinMode(PIN_RAPID, INPUT_PULLUP);

  pinMode(PIN_AXIS_X, INPUT_PULLUP);
  pinMode(PIN_AXIS_Y, INPUT_PULLUP);
  pinMode(PIN_AXIS_Z, INPUT_PULLUP);
  pinMode(PIN_AXIS_4, INPUT_PULLUP);
  pinMode(PIN_AXIS_5, INPUT_PULLUP);
  pinMode(PIN_AXIS_6, INPUT_PULLUP);

  // Encoder signals are generated by powered electronics inside the pendant.
  pinMode(PIN_ENCODER_A_POS, INPUT);
  pinMode(PIN_ENCODER_A_NEG, INPUT);
  pinMode(PIN_ENCODER_B_POS, INPUT);
  pinMode(PIN_ENCODER_B_NEG, INPUT);

  pinMode(PIN_PENDANT_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(PIN_PENDANT_LED, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  configurePins();
  resetEncoder();

  Serial.begin(SERIAL_BAUD);
}

void loop() {
  pollEncoder();
  processSerialCommands();
  updatePendantLed();
  updateNanoLed();
}
```

Save with `Ctrl+O`, `Enter`, then `Ctrl+X`.

## Compile and upload

`/terminal`

```bash
arduino-cli compile \
  —fqbn arduino:avr:nano:cpu=atmega328 \
  ~/Arduino/cdaprod-mpg-nano

arduino-cli upload \
  —port “$NANO_PORT” \
  —fqbn arduino:avr:nano:cpu=atmega328 \
  ~/Arduino/cdaprod-mpg-nano
```

If this Nano uses the common older clone bootloader:

`/terminal`

```bash
arduino-cli compile \
  —fqbn arduino:avr:nano:cpu=atmega328old \
  ~/Arduino/cdaprod-mpg-nano

arduino-cli upload \
  —port “$NANO_PORT” \
  —fqbn arduino:avr:nano:cpu=atmega328old \
  ~/Arduino/cdaprod-mpg-nano
```

## Test through USB

`/terminal`

```bash
arduino-cli monitor \
  —port “$NANO_PORT” \
  —config baudrate=38400
```

Enter:

```text
V
```

Expected:

```text
[V,CDAPROD-MPG-NANO,1.0.0,6AXIS]
```

Enter `J`, rotate the handwheel, and enter `J` again:

```json
{“device”:”cdaprod-mpg-nano”,”axis”:”X”,”axis_id”:1,”step”:10,”step_id”:1,”delta”:3,”estop”:false}
```

If rotation produces the opposite sign from the machine direction, swap **Green/A+** and **White/B+**, or invert it later in software.

One compatibility limitation remains: although the three-bit protocol field can represent axes 5 and 6, the archived UCCNC plugin originally understood only X/Y/Z/4. Your Pi-side integration can use all six immediately through `J`; UCCNC requires the corresponding six-axis plugin update.