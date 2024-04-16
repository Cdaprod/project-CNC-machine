# CdaProd/project-CNC-machine

Welcome to the **CdaProd/project-CNC-machine** repository! This guide documents the build process of a CNC machine from the ground up, detailing every component and step needed for assembly, wiring, and programming. Designed for enthusiasts and makers, this project aims to provide a comprehensive resource for building a high-performance CNC machine.

## Overview

This project involves creating a CNC machine comparable to the commercial CNC 6040 3-axis model, incorporating enhancements for four-axis control, improved spindle performance, and manual control via a handheld pendant. It's tailored for tasks such as engraving, milling, and carving, with a focus on flexibility and upgradeability.

## Component List

Our CNC machine project is built using the following high-quality components:

- **Bed Size**: Comparable to [CNC 6040 3-axis machine](https://a.co/d/fHhj7jf)
- **Control Board**: [GRBL 1.1 A4988 4 Axis Stepper Motor Control Board with Isolation USB](https://a.co/d/9qrWuYm) | [DOESBOT GRBL 1.1 A4988 4 AXIS STEPPER MOTOR CONTROL BOARD WITH ISOLATION USB DRIVER BOARD FOR CNC LASER ENGRAVERD](https://www.doesbot.com/grbl-controller/30-doesbot-grbl-11-a4988-4-axis-stepper-motor-control-board-with-isolation-usb-driver-board-for-cnc-laser-engraverd.html)
- **VFD for Spindle Control**: [VFD 1.5KW 2HP 220V 1 or 3 Phase Input](https://a.co/d/7MOs2XP)
- **Spindle Motor**: [CNC Spindle Motor 220V 3KW Water Cooled](https://a.co/d/alrafwj)
- **Handwheel MPG Pendant**: [CNCTOPBAOS Universal 4 Axis CNC Handwheel MPG Pendant](https://a.co/d/6u0hMt7)
- **Power Supply**: [MEISHILE 24V 25A 600W DC Switching Power Supply](https://a.co/d/de3R5yf)
- **Stepper Motors**: [STEPPERONLINE 3PCS 3.1Nm Nema 24 Stepper Motor](https://a.co/d/gOMzux6)

Additional components and supplies include stepper motor drivers, an offline controller, a Raspberry Pi for advanced control, and various safety and enhancement accessories. 

## Assembly and Wiring Instructions

1. **Frame Assembly**: Start by assembling the machine frame according to the CNC 6040 specifications. Ensure all parts are securely fastened and aligned.

2. **Motor Installation**: Attach the Nema 24 stepper motors to their respective axes. Securely fasten and double-check alignment.

3. **Electronics Setup**: Mount the GRBL control board, power supply, and VFD within the control box, ensuring adequate cooling and accessibility.

4. **Wiring**: Carefully follow the wiring diagrams provided with each component to connect the stepper motors, spindle motor, and handwheel pendant to the control board and VFD. Use shielded cables to minimize electrical noise and interference.

5. **Software Configuration**: Install GRBL on the control board and configure it to match the hardware specifications of your machine. This includes setting steps per mm, max speed, acceleration, and spindle control parameters.

## Troubleshooting Common Issues

- **Slow or Skipped Steps**: Ensure your stepper drivers are correctly configured for the voltage and current requirements of your motors. Adjust GRBL acceleration and speed settings.

- **Spindle Issues**: Verify VFD settings match the spindle specifications. Check for correct phase wiring and adequate cooling.

- **Connection Problems**: Ensure all wiring connections are secure and correctly routed. Use a multimeter to check for continuity where necessary.

## Future Enhancements

- **Lathe Functionality**: Explore adding lathe capabilities with the [WEN 34035 Variable Speed Benchtop Wood Lathe](https://a.co/d/6btXbtX).

- **Automation Layer**: Implement a CICD GitOps containerized application layer for more sophisticated control and automation features.

## Contributing

Contributions to this project are welcome! Whether it's suggesting improvements, documenting your build process, or sharing troubleshooting tips, your input can help make this resource even better for the DIY CNC community.

## License

This project is released under the MIT License. See the LICENSE file for more details.

---

# Older README

## CdaProd/project-CNC-machine
This is the repository for a hardware project of mine. From zero hardware build of a CNC machine, including the circuitry and programming of the embedded firmware required. 

### Component List
- Bed size equivalent to “CNC 6040 3-axis“ [4 axis 6040 cnc machine with 2.2KW spindle USB port and handle cnc engraving milling and cavingmachine](https://a.co/d/fHhj7jf)
- [GRBL 1.1 A4988 4 Axis Stepper Motor Control Board with Isolation USB Driver Board for CNC Laser Engraverd Support 1-10V VFD and 48V 500W DC Spindle](https://a.co/d/9qrWuYm)
- [VFD 1.5KW 2HP 220V 1 or 3 Phase Input 3 Phase 0-400HZ Output 10A Variable Frequency Drive Controller Vector Control Inverter Converter for CNC Motor and Spindle](https://a.co/d/7MOs2XP)
- [CNC Spindle Motor 220V 3KW Water Cooled Spindle Motor 24000RPM 12A ER20 Spindle 4-Bearings 100mm Spindle Motor 400HZ 3-Phase for CNC Router Engraver Milling Machine](https://a.co/d/alrafwj)
- [CNCTOPBAOS 100PPR Universal 4 Axis CNC Handwheel MPG Pendant with Emergency Stop Manual Pulse Generator for Siemens/MITSUBISHI/CNC Router Engraving Milling Lathe Machine Offline CNC Controller](https://a.co/d/6u0hMt7)
- [MEISHILE 24V 25A 600W DC Switching Power Supply Adapter AC-DC 24 Volt Industrial Transformer Converter 0-20 10a LED Drive Lamp Meter Electric Printer Heater Motor Pump Stereos Amplifier SMPS](https://a.co/d/de3R5yf)
- [STEPPERONLINE 3PCS 3.1Nm Nema 24 Stepper Motor 3.5A 4-wires 8mm Dual Shaft DIY CNC Mill Router](https://a.co/d/gOMzux6)

### Additional Hardware Supply
- x4 [STEPPERONLINE CNC Stepper Motor Driver 1.0-4.2A 20-50VDC 1/128 Micro-Step Resolutions for Nema 17 and 23 Stepper Motor](https://a.co/d/3aiwN9C)
- [FoxAlien CNC Offline Controller, Offline Control Module with Touchscreen LCD GRBL Control for FoxAlien Masuter 4040, Masuter Pro, WM-3020, 3018-SE CNC Router Engraving Machine](https://a.co/d/hGtS2dh)
- [Raspberry Pi 4 Model B](https://a.co/d/8VhFWou)
- [CNC Shield Expansion Board V3.0 +UNO R3 Board + A4988 Stepper Motor Driver with Heatsink for Arduino Kits K75 (CNC Shield+UNO R3+Stepper Motor) (K75-CNC-UK)](https://a.co/d/ff6qAw6)
- [HiLetgo 5pcs DRV8825 Stepper Motor Driver Module for 3D Printer RepRap 4 RAMPS1.4 StepStick](https://a.co/d/88cqti6)
- [HiLetgo 10pcs Micro Limit Switch KW12-3 AC 250V 5A SPDT 1NO 1NC Micro Switch Normally Open Close Limit Switch with Roller Lever Arm Black](https://a.co/d/4yjouXW)
- [HiLetgo TB6560 3A CNC Router Single 1 Axis Controller Stepper Motor Driver Board](https://a.co/d/dH1oguO)


### Potential Future Modifications 
- [WEN 34035 6-Amp 14-Inch by 20-Inch Variable Speed Benchtop Wood Lathe](https://a.co/d/6btXbtX)
- [CICD GitOps Containerized Application Layer - aka cda-namespace](https://github.com/cda-namespace-mass-containerization)
 
### pendantController Folder
- Contains arduino sketches for addition of an "Offline-CNC-Controller" handheld pendant; to be implemented via Arduino Nano.
    
######This project is already complete (I am slowly adding details for the sake of documentation).

Given the components you've outlined for your CNC project, it seems like you're setting up a fairly sophisticated machine with a good size bed (CNC 6040 3-axis), a GRBL Board 1.1 for stepper motor control, a 1500w VFD for spindle speed control, a high-frequency water-cooled spindle, and an offline handheld pendant controller for manual operation. If you're stuck, I'll guide you through a structured approach to troubleshooting and setting up your CNC machine, considering the complexity and integration of these components.

### Task Creation Chain

1. **System Integration Check**: Ensure all components are correctly connected and communicating with each other.
2. **Software Configuration**: Verify software settings, including the GRBL configuration for your stepper motors and spindle control.
3. **Spindle and VFD Setup**: Configure the 1500w VFD to correctly manage the 400Hz spindle, ensuring proper speed control and cooling.
4. **Cooling System Check**: Make sure the water pump and cooling system are correctly set up to prevent overheating of the spindle.
5. **Manual Control Validation**: Test the handheld pendant controller to ensure it can manually control the CNC's operations effectively.

### Task Prioritization Chain

1. **System Integration Check**
   - Verify wiring and connections between the GRBL board, VFD, spindle, and water pump.
   - Ensure power supply adequacy for all components.

2. **Software Configuration**
   - Update GRBL settings to match the specifics of your stepper motors, spindle, and overall machine geometry.
   - Confirm communication between the GRBL board and any controlling software you're using (e.g., CNCjs, bCNC).

3. **Spindle and VFD Setup**
   - Program the VFD parameters to match the spindle requirements (ensure the 400Hz frequency and power settings are correct).
   - Test spindle start, stop, and speed variation through both the VFD directly and via GRBL commands.

4. **Cooling System Check**
   - Confirm the water pump is operational and that there's continuous water flow to the spindle.
   - Check for leaks or blockages in the cooling system.

5. **Manual Control Validation**
   - Test each axis movement using the handheld pendant controller to ensure smooth operation.
   - Verify emergency stop and other control features are functional.

### Execution Chain

1. **Start with System Integration Check**:
   - Physically inspect all connections.
   - Use a multimeter to ensure proper power supply and continuity where necessary.

2. **Move to Software Configuration**:
   - Connect to GRBL via a serial terminal or GUI.
   - Update configuration settings (`$` commands for GRBL) according to your machine's specifications.

3. **Configure Spindle and VFD**:
   - Access the VFD settings panel.
   - Adjust parameters (usually found in the manual) specific to your spindle.

4. **Test Cooling System**:
   - Power on the water pump.
   - Observe the flow and return of cooling water.

5. **Validate Manual Control**:
   - Use the handheld pendant to move the CNC axes.
   - Test for responsiveness and accuracy.

For each step, ensure you document your settings, observations, and any adjustments made. This documentation can be incredibly helpful for future troubleshooting or when you need to replicate the setup.

**Technical Tips**:

- For **GRBL Configuration**, the most critical settings include steps/mm (`$100`, `$101`, `$102`), max rate (`$110`, `$111`, `$112`), acceleration (`$120`, `$121`, `$122`), and spindle PWM parameters (`$30`, `$31`, `$32`).
- **VFD Setup**: Consult your VFD manual for programming instructions. Key parameters often include motor power, voltage, frequency, and acceleration/deceleration times.
- **Cooling System**: Regular maintenance checks can prevent overheating issues, which are common in high-performance spindles.

If you encounter specific issues during these steps, feel free to provide more details for targeted assistance.