# Brute Force

---

## BJ_16439_치킨치킨치킨
- C++ STL 중에 순열을 찾을 수 있는 것은 있지만 조합은 없었다..
- 그래서 tree 구조처럼 생각해서 combination() 함수를 구현해봤다
```c++
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int maxSum = 0;
int tempSum = 0;
int chick[30][30];
int selected[3];

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void combination(int idx, int depth);
void getMax();

int main(){
	fastcpp;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> chick[i][j];
		}
	}
	
	combination(-1, -1);
	
	cout << maxSum;
	
	return 0;
}

void combination(int idx, int depth){
	if(depth != -1){
		selected[depth] = idx;
	}
	if(depth == 2){
		getMax();
		return;
	}
	for(int i = idx; i < m; i++){
		combination(i + 1, depth + 1);
	}
}

void getMax(){
	tempSum = 0;
	for(int i = 0; i < n; i++){
		int tempMax = 0;
		for(int j = 0; j < 3; j++){
			tempMax = max(chick[i][selected[j]], tempMax);
		}
		tempSum += tempMax;
	}
	maxSum = max(tempSum, maxSum);
}
```