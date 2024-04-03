# Two Pointer

---

## BJ_1806_부분합
```c++
#include <iostream>
#include <vector>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, s;
    cin >> n >> s;

    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    bool valid = false;
    int start = 0, end = 0;
    int partialSum = v[0];
    int minLen = v.size();

    while(end < n && (start <= end)){
        if(partialSum >= s){
            valid = true;
            if(minLen > (end - start + 1)){
                minLen = end - start + 1;
            }
            partialSum -= v[start];
            ++start;
        }else{
            partialSum += v[++end];
        }
    }

    if(valid){
        cout << minLen;
    }else{
        cout << 0;
    }
    
    return 0;
}

```

---
## BJ_2003_수들의 합 2
```c++
#include <iostream>
#include <vector>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int start = 0, end = 0;
    int sum = v[0];
    int cnt = 0;

    while(end < n && start <= end){
        if(sum < m){
            sum += v[++end];
        }else if(sum > m){
            sum -= v[start];
            ++start;
            if(start > end){
                end = start;
                sum = v[end];
            }
        }else{
            ++cnt;
            sum += v[++end];
            sum -= v[start];
            ++start;
        }
    }

    cout << cnt;

    return 0;
}
```