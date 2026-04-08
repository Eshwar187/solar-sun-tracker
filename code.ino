#include <Servo.h>

Servo myServo;

int leftLDR = A0;
int rightLDR = A1;

int pos = 90;

void setup() {
  myServo.attach(9);
  myServo.write(pos);
}

void loop() {
  int leftValue = analogRead(leftLDR);
  int rightValue = analogRead(rightLDR);

  if (leftValue > rightValue + 50) {
    pos--;
  } 
  else if (rightValue > leftValue + 50) {
    pos++;
  }

  pos = constrain(pos, 0, 180);
  myServo.write(pos);

  delay(50);
}
