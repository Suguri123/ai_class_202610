// 🚪 프로젝트 C: 손으로 여는 문 (서보모터 7번 핀 추가)
//    손가락을 펼수록 문이 열림: 0개 = 0도(닫힘) … 5개 = 90도(활짝)
#include <Servo.h>       // 서보모터를 쉽게 움직이게 해 주는 도구 모음

Servo door;              // 'door'라는 이름의 서보모터
const int SERVO_PIN = 7; // 서보모터 신호선(주황/노랑)은 7번 핀
const int RED = 9;       // 빨강 LED = 문 닫힘
const int YELLOW = 10;   // 노랑 LED = 열리는 중
const int GREEN = 11;    // 초록 LED = 활짝 열림

void setup() {
  Serial.begin(9600);        // 컴퓨터와 대화 시작 (속도 9600)
  door.attach(SERVO_PIN);    // 7번 핀으로 서보모터 조종 시작
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  door.write(0);             // 처음에는 문 닫기 (0도)
  digitalWrite(RED, HIGH);
  Serial.println("문 열기 준비 완료: 0~5 숫자 입력");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '5') {
      int n = c - '0';           // 글자 '5' → 숫자 5
      int angle = n * 18;        // 0, 18, 36, 54, 72, 90도
      door.write(angle);         // 서보모터를 그 각도로 돌리기

      // 불빛으로 문 상태 알려 주기
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
      if (n == 0) {
        digitalWrite(RED, HIGH);      // 닫힘
      } else if (n == 5) {
        digitalWrite(GREEN, HIGH);    // 활짝 열림
      } else {
        digitalWrite(YELLOW, HIGH);   // 조금 열림
      }

      Serial.print("문 각도: ");
      Serial.println(angle);
    }
  }
}
