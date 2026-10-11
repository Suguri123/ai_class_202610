// 🌊 물결: 빨강 → 노랑 → 초록 순서로 하나씩 켜졌다 꺼지기
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀
const int SPEED = 200;   // 다음 불로 넘어가는 시간(밀리초). 숫자가 작을수록 빠름

void setup() {
  pinMode(RED, OUTPUT);      // 세 핀을 모두 출력으로 사용
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);     // 빨강 켜기
  delay(SPEED);
  digitalWrite(RED, LOW);      // 빨강 끄기

  digitalWrite(YELLOW, HIGH);  // 노랑 켜기
  delay(SPEED);
  digitalWrite(YELLOW, LOW);   // 노랑 끄기

  digitalWrite(GREEN, HIGH);   // 초록 켜기
  delay(SPEED);
  digitalWrite(GREEN, LOW);    // 초록 끄기
}
