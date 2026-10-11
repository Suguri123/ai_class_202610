// 🚦 신호등: 초록 4초 → 노랑 1초 → 빨강 3초를 계속 반복
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

void setup() {
  pinMode(RED, OUTPUT);      // 세 핀을 모두 출력으로 사용
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // 1) 초록불 4초
  digitalWrite(GREEN, HIGH);
  delay(4000);
  digitalWrite(GREEN, LOW);

  // 2) 노란불 1초
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);

  // 3) 빨간불 3초
  digitalWrite(RED, HIGH);
  delay(3000);
  digitalWrite(RED, LOW);
}
