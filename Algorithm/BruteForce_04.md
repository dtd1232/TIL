# Brute Force

---

## BJ_2503_숫자야구
- https://www.acmicpc.net/problem/2503
- 이것이야 말로 진짜 브루트포스..
- 4가지 조건을 다 만족시키는 숫자를 찾는다고 생각했음
- 조건을 하나라도 만족시키지 못하는 원소 소거하기
  - 최소 숫자인 123부터 최대 숫자인 987까지 반복
  - 민혁이가 물어본 숫자랑 123~987랑 숫자야구를 함
    - 스트라이크, 볼 개수가 입력된 것과 하나라도 다르면 false
    - 입력된것과 같으면 true
    - 민혁이가 물어본 모든 숫자에 대해 위 과정 반복
  - 최종적으로 true로 남아있는 원소는 4가지 조건을 만족시키는 원소
  - true의 개수를 세서 출력
```c++
#include <iostream>
#include <string>

using namespace std;

bool ans[988] = {true};

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void setTrue();
void isValidNum();

int main(){
	fastcpp;
	
	int n;
	cin >> n;
	
	setTrue();
	
	int guess[n];
	int strike[n];
	int ball[n];
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		cin >> guess[i] >> strike[i] >> ball[i];
	}
	
	isValidNum();
	
	for(int i = 123; i <= 987; i++){
	
		for(int j = 0; j < n; j++){
			int s_cnt = 0;
			int b_cnt = 0;
			
			if(ans[i]){
				string temp = to_string(i);
				string temp2 = to_string(guess[j]);
				
				for(int k = 0; k < 3; k++){
					for(int l = 0; l < 3; l++){
						if(k == l && temp[k] == temp2[l]){
							s_cnt++;
						}
						if(k != l && temp[k] == temp2[l]){
							b_cnt++;
						}
					}
				}
				
				if(s_cnt != strike[j] || b_cnt != ball[j]){
					ans[i] = false;
				}
			}
		}
	}
	
	for(int i = 123; i <= 987; i++){
		if(ans[i]){
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}

void setTrue(){
	for(int i = 123; i <= 987; i++){
		ans[i] = true;
	}
}

void isValidNum(){
	for(int i = 123; i <= 987; i++){
		string temp = to_string(i);
		if(temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0]){
			ans[i] = false;
		}
		if(temp[0] == '0' || temp[1] == '0' || temp[2] == '0'){
			ans[i] = false;
		}
	}
}
```