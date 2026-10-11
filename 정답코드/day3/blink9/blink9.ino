// 💡 9번 핀에 연결한 LED를 1초마다 깜빡이기
const int LED = 9;          // LED가 연결된 핀 번호

void setup() {
  pinMode(LED, OUTPUT);     // 9번 핀을 '출력(내보내기)'으로 사용
}

void loop() {
  digitalWrite(LED, HIGH);  // LED 켜기 (전기 보내기)
  delay(1000);              // 1초(1000밀리초) 기다리기
  digitalWrite(LED, LOW);   // LED 끄기 (전기 끊기)
  delay(1000);              // 1초 기다리기
}
