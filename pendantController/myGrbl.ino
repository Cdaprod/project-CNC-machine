#include <GRBL.h>
#include <examplePins.h>

void setup() {
  // initialize the GRBL library
  GRBL.begin();

  // move the CNC machine to the starting position
  GRBL.move(0, 0, 0);
}

void loop() {
  // read the status of the CNC machine
  int status = GRBL.status();

  // if the machine is idle, send a command to move it to a new position
  if (status == GRBL_STATE_IDLE) {
    GRBL.move(10, 10, 10);
  }
}
