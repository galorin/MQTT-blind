
#include <AccelStepper.h>

#define dirPin D1
#define stepPin D2
#define topEnd D3 //End stop switch placed at the top of the blind for calibration and emergency stop.
#define upButton D4 // Button to manually move blind up.  
#define downButton D5 // Button to manually move blind up.  

#define stepsToClose 10000 // number of steps from fully opened to fully closed.

// The buttons should work as follows
//
// Button click moves blind up/down
// A second click while blind is in motion will stop the blind at that point
// If the end stop is hit before the open command is finished, halt and set 
//   current position to 0

int currentPosition = 0;
int millisPerStep = 50;

AccelStepper blind(1,stepPin,dirPin);

void resetToEndStop() {
	// Check if Endstop is triggerd.
	//  If currently triggered, set current position to 0. Else
	// Lower the blind by 5cm, then execute runToStop().
}

void runToStop() {
	// Movement loop
	//-------------------------------------
	// Move blind a certain number of steps
    // check endstop
	//  if endtop triggered, 
	//    stop loop
	//    set current position to 0
	// end function
	//-------------------------------------
}

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
