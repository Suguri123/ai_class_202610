// 🎹 프로젝트 B: 손가락 피아노 (부저 8번 핀 추가)
//    손가락 1~5 = 도·레·미·파·솔, 0 = 조용히. 손가락 개수가 바뀔 때마다 한 음씩 연주
const int BUZZER = 8;    // 부저는 8번 핀
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

// 음 높이(주파수, Hz). 0번 자리는 '쉼'이라 0
const int NOTES[] = {0, 262, 294, 330, 349, 392};   // 쉼, 도, 레, 미, 파, 솔

// 숫자 n 만큼 LED를 켜는 함수 (최대 3개)
void showLeds(int n) {
  if (n >= 1) digitalWrite(RED, HIGH);    else digitalWrite(RED, LOW);
  if (n >= 2) digitalWrite(YELLOW, HIGH); else digitalWrite(YELLOW, LOW);
  if (n >= 3) digitalWrite(GREEN, HIGH);  else digitalWrite(GREEN, LOW);
}

void setup() {
  Serial.begin(9600);          // 컴퓨터와 대화 시작 (속도 9600)
  pinMode(BUZZER, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  showLeds(0);
  tone(BUZZER, 523, 150);      // 준비 완료 알림음 '삑'
  Serial.println("손가락 피아노 준비 완료: 0~5 숫자 입력");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '5') {
      int n = c - '0';             // 글자 '3' → 숫자 3
      showLeds(n);
      if (n == 0) {
        noTone(BUZZER);            // 0이면 소리 끄기
      } else {
        tone(BUZZER, NOTES[n], 400);   // 해당 음을 0.4초 동안 울리기
      }
      Serial.print("음 번호: ");
      Serial.println(n);
    }
  }
}
