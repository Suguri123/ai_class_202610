// 💡 보드에 붙어 있는 작은 LED(L)를 1초마다 깜빡이기 (선 연결 필요 없음)
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // 보드의 내장 LED(13번 핀)를 출력으로 사용
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // 켜기
  delay(1000);                      // 1초 기다리기
  digitalWrite(LED_BUILTIN, LOW);   // 끄기
  delay(1000);                      // 1초 기다리기
}
