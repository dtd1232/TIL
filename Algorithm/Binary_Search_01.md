# 이분탐색
- 정렬되어 있는 벡터/배열에서 탐색 범위를 절반씩 좁혀가면서 탐색하는 방법
- 정렬되어있지 않으면 사용할 수 없음
- 3개의 변수(start, end, mid)를 사용해서 탐색한다.
    - 찾으려는 값과 mid를 비교한다.
    - 찾으려는 값보다 mid가 크다 -> end를 mid로 설정하고 이분탐색을 한다.
    - 찾으려는 값이 mid보다 크다 -> start를 mid로 설정하고 이분탐색을 한다.
- 시간복잡도: O(log n)

---

### C++ STL

#### **binary_search(first, last, value)**

>**Parameter**<br/>
>first, last: 탐색할 원소들의 범위<br/>
>value: 찾으려는 값

>**Return Value**<br/>
>first와 last 사이에 value가 존재한다면 true, 존재하지 않으면 false를 반환

>**Time Complexity**<br/>
>원소의 갯수가 n개 일때 O(log n)

---

## BJ_1822_차집합\
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vA;
vector<int> vB;
priority_queue<int, vector<int>, greater<int> > ans;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){

	fastcpp;
	
	int nA, nB;
	cin >> nA >> nB;
	
	for(int i = 0; i < nA; i++){
		int temp;
		cin >> temp;
		vA.push_back(temp);
	}
	
	for(int i = 0; i < nB; i++){
		int temp;
		cin >> temp;
		vB.push_back(temp);
	}
	
	sort(vB.begin(), vB.end());
	
	for(int i = 0; i < nA; i++){
		if(!binary_search(vB.begin(), vB.end(), vA[i])){
			ans.push(vA[i]);
		}
	}
	
	if(ans.empty()){
		cout << 0;
	}else{
		cout << ans.size() << "\n";
		while(!ans.empty()){
			cout << ans.top() << " ";
		ans.pop();
		}
	}
	
	return 0;

}
```

---

### BJ_14921_용액합성하기
- 용액합성하기는 이분탐색이 아니라 투포인터로 풀었다. 이분탐색을 사용할 수 있는 방법이 있는지 고민을 해봐야겠다.
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v;
int ans = 200000001;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main() {

fastcpp;
int n;
cin >> n;

while(n--){
	int temp;
	cin >> temp;
	v.push_back(temp);
}

vector<int>::iterator iter = v.begin();
vector<int>::iterator iter2 = v.end() - 1;

while(!(iter >= iter2)){
	int temp = *iter + *iter2;
	if(temp == 0){
		cout << 0;
		return 0;
	}else if(temp > 0){
		if(abs(temp) < abs(ans)){
		ans = temp;
	}
		iter2--;
	}else{
		if(abs(temp) < abs(ans)){
			ans = temp;
		}
		iter++;
	}
}

cout << ans;

return 0;

}

```
