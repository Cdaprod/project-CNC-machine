# Offline Manual Pulse Generator (MPG) Wiring Chart and Translation from Chinese to English
#### By: David Cannan | Cdaprod

Based on the images and the wiring table you provided, we can create a clear wiring diagram to connect your Manual Pulse Generator (MPG) to the printer plug breakout board for your CNC. Here’s a step-by-step guide:

### Wiring Table for the MPG (Manual Pulse Generator)
1. **VCC (Red)**: +5V power supply
2. **0V (Black)**: Ground
3. **A (Green)**: Signal A
4. **B (White)**: Signal B
5. **A- (Violet)**: Complementary signal A- (optional for differential signal transmission)
6. **B- (Purple black)**: Complementary signal B- (optional for differential signal transmission)
7. **X (Yellow)**: Select X-axis
8. **Y (Yellow black)**: Select Y-axis
9. **Z (Brown)**: Select Z-axis
10. **4 (Brown black)**: Select 4th axis
11. **5 (Powder)**: Select 5th axis
12. **6 (Powder black)**: Select 6th axis
13. **X1 (Grey)**: Multiplier x1
14. **X10 (Grey black)**: Multiplier x10
15. **X100 (Orange black)**: Multiplier x100
16. **C (Blue)**: Common for STOP
17. **NC (Blue black)**: Normally Closed for STOP
18. **LED+ (Green)**: LED positive
19. **LED- (Black)**: LED negative
20. **COM (Orange)**: Common terminal

### Printer Plug Breakout Board Pin Assignments
Refer to the breakout board pin numbers and match them with the corresponding MPG wires:

- Pin 1: +5V (connect VCC, Red)
- Pin 2: Ground (connect 0V, Black)
- Pin 3: Signal A (connect A, Green)
- Pin 4: Signal B (connect B, White)
- Pin 5: Complementary signal A- (connect A-, Violet)
- Pin 6: Complementary signal B- (connect B-, Purple black)
- Pin 7: Select X-axis (connect X, Yellow)
- Pin 8: Select Y-axis (connect Y, Yellow black)
- Pin 9: Select Z-axis (connect Z, Brown)
- Pin 10: Select 4th axis (connect 4, Brown black)
- Pin 11: Select 5th axis (connect 5, Powder)
- Pin 12: Select 6th axis (connect 6, Powder black)
- Pin 13: Multiplier x1 (connect X1, Grey)
- Pin 14: Multiplier x10 (connect X10, Grey black)
- Pin 15: Multiplier x100 (connect X100, Orange black)
- Pin 16: Common for STOP (connect C, Blue)
- Pin 17: Normally Closed for STOP (connect NC, Blue black)
- Pin 18: LED positive (connect LED+, Green)
- Pin 19: LED negative (connect LED-, Black)
- Pin 20: Common terminal (connect COM, Orange)

### Steps to Connect the Wires
1. **Identify the Pins on the Breakout Board**: Locate each pin number on the breakout board as shown in the image.
2. **Prepare the Wires**: Strip the ends of the MPG wires if necessary to expose the conductors.
3. **Connect the Wires**: Using the provided wiring table, connect each wire from the MPG to the corresponding pin on the breakout board. Ensure each connection is secure.
4. **Double-Check Connections**: Verify that each wire is connected to the correct pin as per the wiring table.

### Example
If you are connecting the VCC (Red) wire from the MPG to the +5V power supply on the breakout board, you would connect it to pin 1.

### Notes
- Ensure that the power supply is off while making the connections to avoid any accidental shorts or electrical hazards.
- If you encounter any issues with the connections or if the MPG does not function correctly, double-check the wiring table and ensure each wire is securely connected to the correct pin.

By following these steps and using the provided wiring table, you should be able to connect your MPG to the printer plug breakout board correctly.

---

## Research

1. **IMG_9D1518E5-12E7-44E0-8258-48D1BF0CBB1F**:
   - Shows a green wiring connector panel with numbers 1-6 and other numbers up to 25.
   - Appears to be part of a controller device.

2. **IMG_35440B3F-6C88-4D7C-8F07-BA3519994DA1**:
   - Features text written in Chinese.
   - Likely a wiring diagram or information guide for the controller.

3. **IMG_CBBF128C-21AA-4EEB-BC9F-44E95A56E0A9**:
   - Contains additional wiring information and diagrams.

4. **Image C53F1427-75FF-4E00-B259-ED6907D17465**:
   - Has a grid showing wire colors, signals, and their corresponding functions.

5. **Image F945B663-05EC-4EB5-B274-C236507703A7**:
   - Displays information about wiring connections.

Let's summarize the translation of the Chinese text:

- The images show tables with wiring colors and corresponding signal functions. Here's an approximate translation:
  - **红线 (Red line)**: VCC (5V power supply)
  - **黑线 (Black line)**: OV (Ground)
  - **绿线 (Green line)**: A (Signal A)
  - **白线 (White line)**: B (Signal B)
  - **紫线 (Violet line)**: A- (Complementary signal A-)
  - **紫黑线 (Purple black line)**: B- (Complementary signal B-)
  - **黄线 (Yellow line)**: X (Select X-axis)
  - **黄黑线 (Yellow black line)**: Y (Select Y-axis)
  - **棕线 (Brown line)**: Z (Select Z-axis)

This pattern continues with other signal lines for the various axes and control features. These diagrams aim to help you connect wires correctly to the manual pulse generator and the CNC controller.

Please let me know if you want specific information from any diagram or guidance on wiring.

---

Great, you've provided both the MPG wiring schematic and a picture of the CNC controller's connectors. Let's break down the wiring connections based on the information provided.

![Untranslated Manual - Side 1](/images/IMG_35440B3F-6C88-4D7C-8F07-BA3519994DA1.jpeg)

![Untranslated Manual - Side 2](/images/IMG_CBBF128C-21AA-4EEB-BC9F-44E95A56E0A9.jpeg)

![Adapter IMG](/images/IMG_9D1518E5-12E7-44E0-8258-48D1BF0CBB1F.jpeg)

![Query - 1](/images/IMG_2195.png)

![Query - 2](/images/IMG_2202.png)

For the MPG (Manual Pulse Generator):

1. **VCC (Red)**: +5V power supply.
2. **OV (Black)**: Ground.
3. **A (Green)**: Signal A.
4. **B (White)**: Signal B.
5. **A- (Violet)**: Complementary signal A- (optional for differential signal transmission).
6. **B- (Purple black)**: Complementary signal B- (optional for differential signal transmission).
7. **X (Yellow)**: Select X-axis.
8. **Y (Yellow black)**: Select Y-axis.
9. **Z (Brown)**: Select Z-axis.
10. **4 (Brown black)**: Select 4th axis.
11. **5 (Powder)**: Select 5th axis.
12. **6 (Powder black)**: Select 6th axis.
13. **X1 (Grey)**: Multiplier x1.
14. **X10 (Grey black)**: Multiplier x10.
15. **X100 (Orange black)**: Multiplier x100.
16. **C (Blue)**: Common for STOP.
17. **NC (Blue black)**: Normally Closed for STOP.
18. **LED+ (Green)**: LED positive.
19. **LED- (Black)**: LED negative.
20. **COM (Orange)**: Common terminal.

For the CNC controller board:

- You’ve shown a 25-pin D-sub connector, which is a common type for printer port interfaces on CNC controllers.

The usual wiring approach would be to connect:

- **VCC to a +5V power pin** (check your CNC controller’s manual for the exact pin number).
- **OV to a ground pin** (could be pin 18-25 as they are often ground).
- **A and B (and possibly A- and B- if differential signalling is supported)** to the respective pins designated for these signals on the CNC controller.
- **X, Y, Z, 4, 5, 6 axis select signals** to the inputs on the controller that select these axes.
- **X1, X10, X100** to the inputs on the controller that select the multiplier rate.
- **C (common) and NC (normally closed)** might be related to an emergency stop or similar function, so these would go to the corresponding E-stop or control pins.
- **LED+ and LED-** would connect to the power and ground pins if your controller has an output for an LED indicator.

**Here's what you can do next:**

- **Consult the CNC controller's manual** for the pinout of the 25-pin D-sub connector to identify the function of each pin.
- **Match each function from the MPG to the appropriate pin on the CNC controller**. This is where the manual is critical - it will tell you exactly which pins are for power, ground, axis selection, multiplier rates, etc.
- **Make the connections** using the appropriate wiring tools and connectors, making sure to follow safety precautions to avoid shorts and damage to the controller or MPG.

Once you have the pin numbers from your CNC controller's manual, you can use the following pseudocode to create a wiring map:

```plaintext
MPG_to_CNC_Map = {
    "VCC": "CNC_Controller_Pin_for_+5V",
    "OV": "CNC_Controller_Pin_for_GND",
    "A": "CNC_Controller_Pin_for_Signal_A",
    "B": "CNC_Controller_Pin_for_Signal_B",
    ...
    "LED+": "CNC_Controller_Pin_for_LED+",
    "LED-": "CNC_Controller_Pin_for_LED-"
}

for function, pin in MPG_to_CNC_Map.items():
    print(f"Connect MPG {function} wire to CNC controller pin {pin}")
```

Replace `"CNC_Controller_Pin_for_..."` with the actual pin numbers from your manual. This code is not meant to run on a computer; it’s a structured way to represent the connections you need to make.

**Always verify with the CNC controller documentation to ensure correct wiring and avoid damage to the equipment.** If you're ever unsure, it's best to reach out to a professional or the support team for your CNC system.