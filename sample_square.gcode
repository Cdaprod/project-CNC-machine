%
(Start of the Program)
G21 ; Set units to millimeters
G90 ; Absolute positioning
G17 ; XY plane selection

(Safety line - may need to be adjusted based on your CNC)
G28 G91 Z0 ; Move Z to home position
G90

(Start Position)
G0 Z5.0 ; Raise the tool to a safe height of 5mm
G0 X0 Y0 ; Move to the starting position (0,0)

(Square Pattern)
G1 Z-1.0 F100 ; Lower the tool to -1mm at 100mm/min
G1 X40.0 Y0 F500 ; Move 40mm on the X axis
G1 X40.0 Y40.0 F500 ; Move 40mm on the Y axis
G1 X0 Y40.0 F500 ; Move back along the X axis
G1 X0 Y0 F500 ; Close the square by returning to the starting position

(Return to Start Position)
G0 Z5.0 ; Raise the tool to a safe height of 5mm
G0 X0 Y0 ; Move to the starting position (0,0)

(End of the Program)
M30 ; End program and reset to start
%