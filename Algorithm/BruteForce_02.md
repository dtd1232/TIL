# Brute Force

---

## C++ STL

### **substr(from, len)**
- 헤더: ```#include <string>```
- string을 원하는 길이만큼 자르는 함수
- from의 인덱스부터 len 길이만큼 자른 string을 반환
- ```c++
  string s = "abcdefgh";
  // 3번쨰 인덱스 원소에서부터(4번째 원소) 4개의 원소를 반환
  string temp = s.substr(3, 4);
  cout << temp;
  // result:
  // defg
  ```
- len이 남은 문자열보다 길면 문자열 끝까지 반환

### **reverse(first, last)**
- 헤더: ```#include <algorithm>```
- vector, string 등의 순서를 뒤집을 수 있는 함수
- first부터 last까지 뒤집힌 순서를 반환
- ```c++
  vector<int> v = { 10, 40, 50, 30, 20 };
  reverse(v.begin(), v.begin() + 4); // 1~4번째 원소에 대해서만 reverse
  for (int i : v) cout << i << " ";
  // result:
  // 30 50 40 10 20
  ```

---

## BJ_12919_A와B2
- https://www.acmicpc.net/problem/12919
- s문자열에 2개의 연산만으로 t를 만들 수 있는지 판단하는 문제
- 사용 가능한 연산
    - 문자열의 맨 뒤에 A를 추가한다
    - 문자열의 맨 뒤에 B를 추가하고 문자열을 뒤집는다
- 접근 방법: S를 T로 만드는 것이 아니라 T에서 A와 B를 규칙에 따라 제거하면서 S가 나올 수 있는지 판단하기
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s = "";
string t = "";
int convertable = 0;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void dfs(string s, string t);

int main(){
	fastcpp;
	cin >> s >> t;
	
	dfs(s, t);
	
	cout << 0;
	
	return 0;

}

void dfs(string s, string t){
	if(s == t){
		cout << 1;
		exit(0);
	}
	if(s.size() > t.size()){
		return;
	}
	if(t[t.length() - 1] == 'A'){
		string temp;
		temp = t.substr(0, t.length() - 1);
		dfs(s, temp);
	}
	if(t[0] == 'B'){
		string temp;
		temp = t.substr(1, t.length());
		reverse(temp.begin(), temp.end());
		dfs(s, temp);
	}
}
```
