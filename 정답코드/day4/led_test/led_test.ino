// ✅ 세 개의 LED가 잘 연결됐는지 하나씩 켜 보는 테스트 코드
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

void setup() {
  pinMode(RED, OUTPUT);      // 세 핀을 모두 출력으로 사용
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);     // 빨강 켜기
  delay(500);                  // 0.5초 기다리기
  digitalWrite(RED, LOW);      // 빨강 끄기

  digitalWrite(YELLOW, HIGH);  // 노랑 켜기
  delay(500);
  digitalWrite(YELLOW, LOW);   // 노랑 끄기

  digitalWrite(GREEN, HIGH);   // 초록 켜기
  delay(500);
  digitalWrite(GREEN, LOW);    // 초록 끄기

  digitalWrite(RED, HIGH);     // 세 개 모두 켜기
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(1000);                 // 1초 동안 유지

  digitalWrite(RED, LOW);      // 세 개 모두 끄기
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(500);
}
