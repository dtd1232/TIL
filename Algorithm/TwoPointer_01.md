# Two Pointer
- 한개의 배열에서 2개의 포인터를 이용해서 특정 값 2개 또는 포인터 사이의 범위가 조건을 만족하는지 확인
---

## BJ_2230_수고르기

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int>::iterator iter1 = v.begin();
    vector<int>::iterator iter2 = v.begin() + 1;

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int minSub = *(v.end()-1) - *v.begin() + 1;

    while(iter2 != v.end()){
        if((*iter2 - *iter1) == m){
            cout << m;
            return 0;
        }

        if((*iter2 - *iter1) < minSub && (*iter2 - *iter1 > m)){
            minSub = *iter2 - *iter1;
            ++iter1;
        }
        if((*iter2 - *iter1) < m){
            ++iter2;
        }else{
            if((*iter2 - *iter1) < minSub){
                minSub = *iter2 - *iter1;
            }
            ++iter1;
        }
    }

    cout << minSub;

    return 0;
}
```