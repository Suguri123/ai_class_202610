// 🫧 숨쉬기: 세 LED가 천천히 밝아졌다가 어두워지기 (analogWrite로 밝기 조절)
const int RED = 9;       // 빨강 LED는 9번 핀 (~ 표시가 있는 핀이라 밝기 조절 가능)
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

// 세 LED의 밝기를 한 번에 정하는 함수 (0 = 꺼짐, 255 = 가장 밝게)
void setAll(int brightness) {
  analogWrite(RED, brightness);
  analogWrite(YELLOW, brightness);
  analogWrite(GREEN, brightness);
}

void setup() {
  pinMode(RED, OUTPUT);      // 세 핀을 모두 출력으로 사용
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  for (int b = 0; b <= 255; b = b + 5) {   // 0 → 255 : 점점 밝게
    setAll(b);
    delay(20);
  }
  for (int b = 255; b >= 0; b = b - 5) {   // 255 → 0 : 점점 어둡게
    setAll(b);
    delay(20);
  }
}
