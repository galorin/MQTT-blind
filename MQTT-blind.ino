#include <AccelStepper.h>

#define dirPin D1
#define stepPin D2

AccelStepper blind(1,stepPin,dirPin);

void setup() {
  // put your setup code here, to run once:
blind.setMaxSpeed(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
blind.setSpeed(400);
blind.runSpeed();
}
