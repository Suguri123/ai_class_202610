// 🆘 모스부호 SOS: 짧게 3번(S) → 길게 3번(O) → 짧게 3번(S)
const int LED = 9;              // LED가 연결된 핀 번호

// LED를 onTime(밀리초) 동안 켰다가 끄는 함수
void blinkLed(int onTime) {
  digitalWrite(LED, HIGH);      // 켜기
  delay(onTime);                // onTime 만큼 기다리기
  digitalWrite(LED, LOW);       // 끄기
  delay(200);                   // 깜빡임 사이 쉬는 시간 0.2초
}

void setup() {
  pinMode(LED, OUTPUT);         // 9번 핀을 출력으로 사용
}

void loop() {
  for (int i = 0; i < 3; i++) {
    blinkLed(200);              // S: 짧게 (0.2초) 3번
  }
  for (int i = 0; i < 3; i++) {
    blinkLed(600);              // O: 길게 (0.6초) 3번
  }
  for (int i = 0; i < 3; i++) {
    blinkLed(200);              // S: 짧게 3번
  }
  delay(2000);                  // 2초 쉬었다가 처음부터 다시
}
