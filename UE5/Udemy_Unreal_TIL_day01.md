> Udemy - Unreal Engine 5 C++ 개발자: C++ 학습하고 비디오 게임 제작하기
## Glossary
- Event Graph - 블루프린트의 캔버스, 노드를 이용해 다양한 기능을 만들 수 있다.
- Node - 블루프린트에서 사용할 수 있는 미리 만들어진 기능들
- Event - 사건이 언제 발생해야 하는지에 대한 정보를 가지는 노드
- Pin - 노드를 연결할 수 있는 소켓(왼쪽: 언제 실행 될 것인지, 오른쪽: 다음에 어떤 동작을 할 것인지)
- <img src="https://github.com/dtd1232/TIL/blob/main/UE5/img/day01_Event_Blueprint.png?raw=true" width="500">
- 플레이를 시작할 때 Hello라는 string을 출력하고 Welcome to Warehouse Wreckage!라는 string을 출력한다.

## Physics
- 디테일 -> 피직스 -> 피직스 시뮬레이트를 한다면 해당 오브젝트에 중력 등의 물리 법칙을 적용할 수 있음.
- 중력을 적용하거나 해제하고 싶으면 디테일 -> 피직스 -> 중력 활성화를 설정하면 된다.
- 질량(kg)은 기본적으로 에셋에 따라 계산된다. 체크박스에 체크하고 직접 설정할 수 있다.
- <img src="https://github.com/dtd1232/TIL/blob/main/UE5/img/day01_Physics.png?raw=true" width="500">