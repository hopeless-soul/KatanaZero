# KatanaZero
## 개발환경
C++ VS2019 DirectX FMOD Git 
## 조작법
P 디버그 토글 O 디버그 타임 토글 I 디버그 그리드 토글
치트 F1 리플레이 진입 F2 무적 F3 시간 되감기
Q 아이템 사용 SPACE BAR 상호작용
나머지는 카타나제로 원작과 동일 WASD 이동 마우스 사용 
## 일반상태에서 잔상 남기며 그리기
현재 생각중인 색깔
AfterStartColor = 0,255,255
AfterGoalColor = 보라색
슬로우 시간이 끝났다고 해서 잔상을 지우는게 아니고 알파가 0이여야 지우는 거임 슬로우가 끝나면 델타가 커져서 어짜피 빨리 없어짐 !
## 슬로우 상태
현재 생각중인 색깔
SlowGoalColor = 0,255,255
AfterGoalColor = 255,0.135
1. 슬로우 상태로 진입 할시 잔상을 클리어 CurrentColor 는 SlowGoalColor 로 틱마다 선형보간 
2. 슬로우 상태에서 탈출 할시 CurrentColor 는 틱마다 본래의 255,255,255 로 선형보간
3. 슬로우 상태로 진입하고나서 일정 시간이 지날때마다 잔상을 푸시 
여기서 잔상의 색깔은 현재의 보간중인 색깔로 저장
4. 잔상들은 틱마다 알파가 0으로 선형으로 감소 (여기서 알파가 0보다 작으면 잔상을 삭제)
5. 잔상들은 색깔이 AfterGoalColor 로 선형보간

### 일반
알파가 선형으로 감소하면서
주인공과 공격 슬래쉬는 (에메랄드->분홍?보라 그라데이션) 색깔로 렌더링하며 잔상은 알파값 선형으로 감소
피격자도 피격당한 순간부터 잠시 (에메랄드->분홍?보라 그라데이션) 색깔로 렌더링하며 잔상은 알파값 선형으로 감소
### 슬로우 모션일때는 (슬로우 모션으로 진입할때의 GoalColor 도 모두 선형보간 [ex) 원래 컬러 -> 에메랄드])
총알 , 피 , 등은 원래 컬러 그대로 렌더링
주인공과 공격 슬래쉬 잔상 에메랄드로 렌더하며 알파가 선형으로 감소
## 공격 슬래쉬
그냥 플레이
## 피격시 
피격위치에 상처? 이펙트
카메라 흔들림

1.공격자 -> 피격자 방향으로 핏방울 이펙트 공격

2.공격자 -> 피격자 방향으로 화면 전체 사이즈 절반 정도의 직선 이펙트 렌더링
(여기서 이펙트의 중앙이 알파가 제일 높고 중앙에서 벗어날수록 알파 감소)
보라색 에메랄드 색으로 일정 시간마다 교체하며 공격자->피격자 방향으로 이펙트 위치 이동
## 시간 되돌리기
이전 렌더링 위치 를 일정수만큼 저장한 이후
(이건 이펙트,캐릭터만 해당되며 맵과 맵의 핏자국은 아님)
스택의 일정 숫자만큼 렌더링하며 스택의 제일 최근 부분은 알파가 제일 높고
스택의 아래부분으로 갈수록 알파가 감소

## 효과를 위한 포토샵 테크닉
1. 이미지를 백업한다.
2. 이미지를 켠다.
3. 녹화를 시작한다.
4. Ctrl+A 로 전체선택 한후 V로 이동가능하게 만든다.
5. → ← 트릭으로 알파를 제외한 이미지만 선택한다
6. M 을 눌러서 선택한 픽셀들에게 명령 가능한 상태로 만든다.
7. Fill 로 이미지에 원하는 색깔로 채운다.
8. 다음 Save 한다.
9. 매크로 레코딩을 종료한다.
10.이미지들을 백업해서 폴더에 저장한다.
10. Automate 에 Batch 기능으로 매크로를 사용한다.
11. Include SubFolder 체크한다. 



