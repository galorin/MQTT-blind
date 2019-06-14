#include <AccelStepper.h>

#define dirPin D1
#define stepPin D2
#define topEnd D3 //End stop switch placed at the top of the blind for calibration and emergency stop.
#define upButton D4 // Button to manually move blind up.  
#define downButton D5 // Button to manually move blind up.  

// The buttons should work as follows
//
// Button click moves blind up/down
// A second click while blind is in motion will stop the blind at that point

AccelStepper blind(1,stepPin,dirPin);

void setup() {
  // put your setup code here, to run once:
  blind.setMaxSpeed(1000);
  // initialize input pins.
}

void loop() {
  // put your main code here, to run repeatedly:
blind.setSpeed(400);
blind.runSpeed();
}
