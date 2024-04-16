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