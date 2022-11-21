#define J_VRX 0
#define J_VRY 1
#define J_SW 3

void setup() {
  Serial.begin(9600);
  pinMode(J_SW, INPUT_PULLUP);
}

void loop() {
  int x = map(analogRead(J_VRX), 0, 1023, -512, 512)
  Serial.print(x);
  Serial.print(',');
  int y = map(analogRead(J_VRY), 0, 1023, -512, 512);
  Serial.print(y);
  Serial.print(',');
  Serial.println(digitalRead(J_SW) * 100);
}
