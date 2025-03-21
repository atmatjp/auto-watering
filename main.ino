int thresholdLow = 450;  // ポンプONの閾値
int thresholdHigh = 490; // ポンプOFFの閾値
bool pumpState = false;  // ポンプの状態（初期値OFF）

void loop() {
  value1 = analogRead(Pin1);
  Serial.print("MOISTURE LEVEL:");
  Serial.println(value1);

  if (!pumpState && value1 < thresholdLow) {
    digitalWrite(IN1, HIGH); // ポンプON
    pumpState = true;
  } else if (pumpState && value1 > thresholdHigh) {
    digitalWrite(IN1, LOW); // ポンプOFF
    pumpState = false;
  }

  delay(1000);
}
