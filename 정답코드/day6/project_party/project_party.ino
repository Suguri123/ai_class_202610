// 🎉 프로젝트 A: 손 신호등 & LED 파티 (부품 추가 없음)
//    손가락 0 = 모두 끄기, 1 = 빨강, 2 = 노랑, 3 = 초록, 4 = 물결, 5 = 파티(모두 깜빡깜빡)
const int RED = 9;       // 빨강 LED는 9번 핀
const int YELLOW = 10;   // 노랑 LED는 10번 핀
const int GREEN = 11;    // 초록 LED는 11번 핀

int mode = 0;                 // 지금 모드 (받은 숫자)
int step = 0;                 // 움직이는 불빛이 몇 번째 단계인지
unsigned long lastTime = 0;   // 마지막으로 불빛을 바꾼 시각 (밀리초)

// 세 LED를 한 번에 켜고 끄는 함수 (HIGH = 켜기, LOW = 끄기)
void setLeds(int r, int y, int g) {
  digitalWrite(RED, r);
  digitalWrite(YELLOW, y);
  digitalWrite(GREEN, g);
}

void setup() {
  Serial.begin(9600);         // 컴퓨터와 대화 시작 (속도 9600)
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  setLeds(LOW, LOW, LOW);     // 처음에는 모두 끄기
  Serial.println("LED 파티 준비 완료: 0~5 숫자 입력");
}

void loop() {
  // 1) 새 숫자가 들어왔는지 확인하기
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '5') {
      mode = c - '0';         // 글자 '4' → 숫자 4
      step = 0;
      Serial.print("모드: ");
      Serial.println(mode);
      if (mode == 0) setLeds(LOW, LOW, LOW);    // 모두 끄기
      if (mode == 1) setLeds(HIGH, LOW, LOW);   // 빨강만
      if (mode == 2) setLeds(LOW, HIGH, LOW);   // 노랑만
      if (mode == 3) setLeds(LOW, LOW, HIGH);   // 초록만
    }
  }

  // 2) 움직이는 불빛 (delay 대신 millis 사용 → 움직이는 중에도 새 숫자를 바로 받음)
  unsigned long now = millis();               // 아두이노가 켜진 뒤 지난 시간

  if (mode == 4 && now - lastTime >= 200) {   // 물결: 0.2초마다 다음 LED로
    lastTime = now;
    if (step == 0) setLeds(HIGH, LOW, LOW);
    if (step == 1) setLeds(LOW, HIGH, LOW);
    if (step == 2) setLeds(LOW, LOW, HIGH);
    step = step + 1;
    if (step > 2) step = 0;                   // 마지막 다음엔 처음으로
  }

  if (mode == 5 && now - lastTime >= 150) {   // 파티: 0.15초마다 모두 깜빡
    lastTime = now;
    if (step == 0) {
      setLeds(HIGH, HIGH, HIGH);
      step = 1;
    } else {
      setLeds(LOW, LOW, LOW);
      step = 0;
    }
  }
}
