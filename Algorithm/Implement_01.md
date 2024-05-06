# 구현

---
## BJ_20291_파일정리

- 분명 로직은 맞게 짰는데 실패를 2번이나 했다..
- 몇번 시도해본 결과, sizeof() 대신 length()를 사용하니까 해결됐다
- str.length(): str의 실제 길이 반환
- sizeof(str): 변수 str의 자료형의 크기 반환
- str.capacity(): 시스템에서 할당받은 용량을 반환
- string 자료형의 길이를 구할땐 length(), vector의 길이를 구할땐 size()를 쓰자

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

    // 확장자, 개수
    vector<pair<string, int> > v;
    vector<string> inputString;

    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        int dotIdx = str.find('.');
        inputString.push_back(str.substr(dotIdx+1, str.length()));
    }

    sort(inputString.begin(), inputString.end());

    string temp = inputString[0];
    int cnt = 0;

    for(int i = 0; i < n; ++i){
        if(inputString[i] == temp){
            cnt++;
        }else if(inputString[i] != temp){
            v.push_back(make_pair(temp, cnt));
            temp = inputString[i];
            cnt = 1;
        }
    }
    
    v.push_back(make_pair(temp, cnt));

    for(int i = 0; i < v.size(); ++i){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
```