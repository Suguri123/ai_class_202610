# 🤖 AI 에이전트와 피지컬 컴퓨팅 입문 · 교육자료

학생들을 위한 강의 실습 자료 및 정답 코드 저장소입니다.

> 🌐 **온라인 실습 웹사이트 바로가기**: **[https://suguri123.github.io/ai_class_202610/](https://suguri123.github.io/ai_class_202610/)**  
> *(별도 프로그램 설치 없이 브라우저에서 바로 따라 할 수 있는 실습 가이드 사이트입니다)*

---

## 📂 폴더 및 파일 구조

| 폴더 / 파일 | 설명 |
| :--- | :--- |
| **[`정답코드/`](./정답코드)** | 1차시부터 6차시까지 실습 예제 및 정답 코드 (수강생 노트북의 `C:\ai-class` 구조와 동일) |
| **[`배선도/`](./배선도)** | 아두이노 및 부품 연결 배선도 원본 이미지 (PNG) |
| **[`Firebase_규칙/`](./Firebase_규칙)** | 6차시 응원 방명록용 Cloud Firestore 보안 규칙 파일 (`firestore_rules_guestbook.txt`) |
| **[`디자인/`](./디자인)** | 실습 사이트 기준 색상 테마 및 PowerPoint 템플릿 (`기본_색상_템플릿.pptx`) |
| **[`실습사이트_오프라인.html`](./실습사이트_오프라인.html)** | 오프라인 환경(USB/로컬)에서도 실행 가능한 단계별 실습 안내 웹페이지 |
| **[`먼저_읽기.txt`](./먼저_읽기.txt)** | 전체 강의자료 요약 안내문 원본 |

---

## 💻 차시별 정답코드 가이드 (`정답코드/`)

각 차시별 폴더에는 AI 비서 지침용 규칙표(`AGENTS.md`)가 포함되어 있습니다.  
실습 중 막힌 차시의 파일만 같은 위치에 복사하여 사용하세요.

- **`day1/`**: 
  - `index.html`: 자기소개 페이지 예시 (1차시 콘솔창 `agy` 사용)
- **`day2/`**: 
  - `index.html`: 자기소개 + '손 인식 체험하기' 버튼
  - `hand.html`: 웹캠 기반 AI 손 인식 (인터넷 연결 필요)
  - 🌐 *GitHub Pages(`아이디.github.io`)에 업로드하여 웹 배포*
- **`day3/`**: 아두이노 기본 제어
  - `blink_builtin`: 아두이노 내장 LED 깜빡이기
  - `blink9`: 9번 핀 외장 LED 제어
  - `sos`: 모스 부호 SOS 신호 출력
- **`day4/`**: LED 활용 및 시리얼 통신
  - `led_test`: 기본 LED 테스트
  - `traffic`: 신호등 시뮬레이션
  - `wave`: 파도타기 효과
  - `breathe`: PWM 숨쉬기 효과
  - `led_receiver`: 시리얼 통신 명령 수신 스케치
- **`day5/`**: AI와 아두이노 결합
  - `hand.html`: 손 인식 모델
  - `hand_led.html`: 손 인식 제스처 + 아두이노 시리얼 연동 (6차시 작품 리모컨 역할)
  - `led_receiver`: 아두이노 수신 스케치
- **`day6/`**: 최종 창작 프로젝트
  - `project_party`: 파티 조명 프로젝트
  - `project_piano`: 손 제스처 피아노 프로젝트
  - `project_door`: 스마트 도어 제어 프로젝트
  - `project_mood`: 무드등 프로젝트
  - `index.html`: 내 사이트 + Firebase 응원 방명록
  - `hand.html`, `hand_led.html`

---

## 🔌 하드웨어 핀(Pin) 배치 기준표

| 부품 | 아두이노 핀 번호 | 비고 |
| :--- | :---: | :--- |
| **빨강 LED** | `9번` | 디지털 / PWM |
| **노랑 LED** | `10번` | 디지털 / PWM |
| **초록 LED** | `11번` | 디지털 / PWM |
| **부저 (Buzzer)** | `8번` | 디지털 |
| **서보 모터 (Servo)** | `7번` | 디지털 제어신호 |
| **RGB LED** | `3번, 5번, 6번` | PWM 핀 |
| **시리얼 통신 속도** | `9600 bps` | Web Serial 통신 기본값 |

---

## 🌐 웹 공유 & Firebase 설정 안내

### 1. GitHub Pages 웹 배포 (2차시)
1. GitHub에서 저장소 이름을 `[내아이디].github.io`로 생성 (공개 저장소).
2. `day2/` 폴더 안의 파일들을 저장소 루트에 업로드 후 커밋.
3. 저장소 **Settings → Pages** 메뉴에서 Source를 `main` 브랜치 / `(root)`로 설정 후 Save.
4. 약 1~2분 후 `https://[내아이디].github.io`로 전 세계 어디서든 접속 가능.

### 2. 응원 방명록 Firebase 연동 (6차시)
1. [Firebase 콘솔](https://console.firebase.google.com/)에서 새 프로젝트 생성 (무료 Spark 요금제).
2. 웹 앱 등록 후 발급된 `firebaseConfig` 객체를 `day6/index.html` 파일에 반영.
3. **Cloud Firestore** 데이터베이스 생성 (위치: `asia-northeast3 (Seoul)`, 테스트 모드로 시작).
4. `Firebase_규칙/firestore_rules_guestbook.txt`의 보안 규칙을 복사하여 Firestore '규칙(Rules)' 탭에 붙여넣고 [게시].
