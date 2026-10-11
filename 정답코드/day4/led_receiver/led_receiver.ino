// 📨 컴퓨터에서 숫자(0~5)를 받아 LED를 켜는 '수신기' 코드
//    시리얼 모니터 직접 입력 또는 5차시 손 인식 웹페이지에서 전송
//    0 = 모두 끄기, 1 = 빨강, 2 = 빨강+노랑, 3·4·5 = 세 개 모두
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

// 숫자 n 만큼 LED를 켜는 함수 (최대 3개)
void showLeds(int n) {
  if (n >= 1) {
    digitalWrite(RED, HIGH);     // 1 이상이면 빨강 켜기
  } else {
    digitalWrite(RED, LOW);
  }
  if (n >= 2) {
    digitalWrite(YELLOW, HIGH);  // 2 이상이면 노랑 켜기
  } else {
    digitalWrite(YELLOW, LOW);
  }
  if (n >= 3) {
    digitalWrite(GREEN, HIGH);   // 3 이상이면 초록 켜기
  } else {
    digitalWrite(GREEN, LOW);
  }
}

void setup() {
  Serial.begin(9600);            // 컴퓨터와 대화 시작 (속도 9600)
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  showLeds(0);                   // 처음에는 모두 끄기
  Serial.println("준비 완료: 0~5 숫자 입력");
}

void loop() {
  if (Serial.available() > 0) {  // 컴퓨터가 보낸 글자가 있으면
    char c = Serial.read();      // 글자 하나 읽기
    if (c >= '0' && c <= '5') {  // 0~5 숫자일 때만 반응 (엔터 같은 다른 글자는 무시)
      int n = c - '0';           // 글자 '3' → 숫자 3 으로 바꾸기
      showLeds(n);
      Serial.print("받은 숫자: ");
      Serial.println(n);         // 받은 숫자를 컴퓨터에 다시 알려 주기
    }
  }
}
