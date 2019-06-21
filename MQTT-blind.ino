
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

int millisPerStep = 20;

enum movementEnum {
	MovingDown.
	Stopped,
	MovingUp
};

movementEnum move = Stopped;

AccelStepper blind(1,stepPin,dirPin);

void setup() {
  // put your setup code here, to run once:
  blind.setMaxSpeed(1000);
  // initialize input pins.
  pinMode(topEnd, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(topEnd), endStopHit, RISING);
  attachInterrupt(digitalPinToInterrupt(upButton), openCall, RISING);
  attachInterrupt(digitalPinToInterrupt(downButton), closeCall, RISING);
  resetToEndStop();
  blind.setSpeed(800);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // while moving up, move up by one step until 
  if (movingUp && !movingDown) {
	  if (blind.currentPosition() >=0)
	  blind.moveTo(blind.currentPosition() -10);
  }
  if (movingDown && !movingUp) {
	  
  }
}

void endStopHit()
{
	blind.stop();
	blind.setCurrentPosition = 0;
	movingUp = false;
	movingDown = false;
}

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

// If currently closing, stop and reverse direction.  
// If opening, stop.
// If not moving, start opening
void openCall() {
	movingDown = false;
	movingUp = !movingUp;
}

void closeCall() {
	
}
