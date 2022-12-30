#define J_VRX 0
#define J_VRY 1

#define R_PIN 6
#define G_PIN 5
#define B_PIN 3

#include <GRGB.h>
GRGB led(COMMON_CATHODE, R_PIN, G_PIN, B_PIN);

const double colorWheelAngleCoeff = 1530;

void setup() {
  Serial.begin(9600);
  Serial.println(colorWheelAngleCoeff);

  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
}

void loop() {
  int realX = analogRead(J_VRX);
  int x = map(realX, 0, 1023, -512, 511);
  //int x = analogRead(J_VRX);
  Serial.print(x);
  Serial.print(',');
  int realY = analogRead(J_VRY);
  int y = map(realY, 0, 1023, -512, 511);
  //int y = analogRead(J_VRY);
  Serial.print(y);
  Serial.print(" ");
  double angle = atan2(y, x);
  Serial.print(angle);
  //Serial.println(digitalRead(J_SW) * 100);

  double normalizedAngle = ((angle / PI) + 1) / 2;
  Serial.print(" ");
  Serial.print(normalizedAngle);
  double normalizedX = (double)x / (double)512.0;
  Serial.print(" ");
  Serial.print(normalizedX);
  double normalizedY = (double)y / (double)512.0;
  Serial.print(" ");
  Serial.print(normalizedY);
  double squaredX = normalizedX * normalizedX;
  Serial.print(" ");
  Serial.print(squaredX);
  double squaredY = normalizedY * normalizedY;
  Serial.print(" ");
  Serial.print(squaredY);
  double length = sqrt(squaredX + squaredY);
  Serial.print(" ");
  Serial.println(length);
  double clampedLength = constrain(length, 0, 1);
  led.setWheel( (int)(colorWheelAngleCoeff * normalizedAngle), clampedLength * 255);
}