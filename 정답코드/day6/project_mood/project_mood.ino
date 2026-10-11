// 🌈 프로젝트 D: 손으로 바꾸는 무드등 (RGB LED: 빨강 3번, 초록 5번, 파랑 6번 핀)
//    0 = 끄기, 1 = 빨강, 2 = 초록, 3 = 파랑, 4 = 보라, 5 = 무지개
const int R_PIN = 3;       // RGB LED 빨강 다리 (220Ω 저항 거쳐서)
const int G_PIN = 5;       // RGB LED 초록 다리
const int B_PIN = 6;       // RGB LED 파랑 다리
const bool COMMON_ANODE = false;  // 가장 긴 다리를 5V에 꽂는 '공통 양극형'이면 true로 변경

int mode = 0;                 // 지금 모드 (받은 숫자)
int hue = 0;                  // 무지개 색 위치 (0~359)
unsigned long lastTime = 0;   // 마지막으로 색을 바꾼 시각

// 빨강·초록·파랑 밝기(0~255)로 색 만들기
void setColor(int r, int g, int b) {
  if (COMMON_ANODE) {         // 공통 양극형은 밝기를 거꾸로 적용
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  }
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}

// 무지개 색 계산: 색 위치(0~359) → 빨강 → 초록 → 파랑 → 다시 빨강
void rainbow(int h) {
  int x = h % 120;            // 120 구간 안에서의 위치 (0~119)
  int up = x * 255 / 120;     // 점점 커지는 값 0 → 255
  int down = 255 - up;        // 점점 작아지는 값 255 → 0
  if (h < 120) {
    setColor(down, up, 0);    // 빨강 → 초록
  } else if (h < 240) {
    setColor(0, down, up);    // 초록 → 파랑
  } else {
    setColor(up, 0, down);    // 파랑 → 빨강
  }
}

void setup() {
  Serial.begin(9600);         // 컴퓨터와 대화 시작 (속도 9600)
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  setColor(0, 0, 0);          // 처음에는 끄기
  Serial.println("무드등 준비 완료: 0~5 숫자 입력");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '5') {
      mode = c - '0';
      if (mode == 0) setColor(0, 0, 0);       // 끄기
      if (mode == 1) setColor(255, 0, 0);     // 빨강
      if (mode == 2) setColor(0, 255, 0);     // 초록
      if (mode == 3) setColor(0, 0, 255);     // 파랑
      if (mode == 4) setColor(160, 0, 255);   // 보라
      Serial.print("색 모드: ");
      Serial.println(mode);
    }
  }

  // 무지개 모드: 0.02초마다 색을 조금씩 바꾸기 (delay 대신 millis 사용)
  if (mode == 5 && millis() - lastTime >= 20) {
    lastTime = millis();
    hue = hue + 1;
    if (hue >= 360) hue = 0;
    rainbow(hue);
  }
}
