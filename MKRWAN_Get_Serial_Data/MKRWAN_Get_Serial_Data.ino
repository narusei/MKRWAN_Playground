void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  Serial1.begin(9600);
  while(!Serial1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available()) {
    String userId = Serial1.readStringUntil('\n');
    Serial.println(userId);
    userId.remove(4);
    Serial.println(userId.length());
    Serial.println(userId);
  }
}
