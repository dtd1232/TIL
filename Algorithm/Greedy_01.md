# Greedy Algorithm
- 현재 상태에서 최적의 답을 찾는 알고리즘
- 관찰을 통해 탐색 범위를 줄이는 것

---

## BJ_1931_회의실배정
- 특정 회의가 끝난 시점 이후에 시작하는 회의를 선택해야 함
  - 그 중에 가장 빨리 끝나는 회의를 선택해야 함
  - 가장 빨리 끝나는 회의를 찾기 위해서 끝나는 시간 기준으로 정렬
- 현재 상태(회의가 끝나는 시간)를 기준으로, 이후에 시작하는 회의 중 가장 빨리 끝나는 것을 찾음(최적해)

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
	fastcpp;
	
	int n;
	cin >> n;
	
	// end time, start time
	vector<pair<int, int> > v;
	int cnt = 1;
	
	for(int i = 0; i < n; i++){
		int st, et;
		cin >> st >> et;
		v.push_back(make_pair(et, st));
	}
	
	// sort by endtime
	sort(v.begin(), v.end());
	int cur_et = v[0].first;
	  
	for(int i = 1; i < n; i++){
		if(v[i].second >= cur_et){
			cnt++;
			cur_et = v[i].first;
		}
	}
	
	cout << cnt;
	
	return 0;
}
```

### BJ_11047_동전0
```c++
#include <iostream>
#include <vector>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
	fastcpp;
	
	int n, k;
	cin >> n >> k;
	
	vector<int> v;
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i = n - 1; i >= 0; i--){
		ans += k / v[i];
		k %= v[i];
	}
	
	cout << ans;
	
	return 0;
}
```