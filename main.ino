const int IN1 = 2;    //ポンプの制御ピン
const int Pin1 = A0;  //湿度センサのピン
const int THRESHOLD = 470; //湿度のしきい値
const int READ_TIMES = 5;  //センサー値を読み取り回数

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  
  //初期状態でポンプをOFFにしておく
  digitalWrite(IN1, LOW);
}

void loop() {
  float value1 = 0;
  
  for (int i = 0; i < READ_TIMES; i++) {
    value1 += analogRead(Pin1);
    delay(10);  //10ms待機
  }
  value1 /= READ_TIMES;

  //湿度数の出力
  Serial.print("MOISTURE LEVEL: ");
  Serial.println(value1);

  //値に応じてポンプを制御
  if (value1 > THRESHOLD) {
    digitalWrite(IN1, LOW);  //OFF
  } else {
    digitalWrite(IN1, HIGH); //ON
  }

  Serial.println();
  delay(1000); // 1秒ごとに測定
}
