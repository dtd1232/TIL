# Brute Force
- 완전탐색 알고리즘 - 가능한 모든 경우를 탐색하는 방법
- 무조건 정답을 출력하지만 시간 복잡도가 높다.
- 구조에 따라 탐색 방법이 달라짐
  - 선형구조 - 순차탐색: 자료를 선형 구조로 바꾸고 탐색
  - 비선형구조 - BFS, DFS

---
## C++ STL

### **Set**
- 균형 이진트리 자료구조를 기반으로 만들어짐
- 들어온 원소들은 자동으로 오름차순으로 정렬됨
- 원소들은 중복으로 저장되지 않음

### **next_permutation(first, last)**
- 순열(4P2 등)을 생성하는 함수
>**Parameter**<br/>
>first, last: 탐색할 원소들의 범위

>**Return Value**
>오름차순으로 순열을 생성

---

## BJ_5568_카드놓기

```c++
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
vector<string> cards;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
	fastcpp;
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		cards.push_back(temp);
	}
	
	sort(cards.begin(), cards.end());
	
	set<string> ans;
	
	do{
		string s = "";
		for(int i = 0; i < k; i++){
			s += cards[i];
		}
		ans.insert(s);
	}while(next_permutation(cards.begin(), cards.end()));
	
	cout << ans.size();
	
	return 0;
}
```