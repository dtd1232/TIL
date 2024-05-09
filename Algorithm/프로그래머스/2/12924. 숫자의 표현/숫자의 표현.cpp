#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    int r = -1;
    int l = 0;
    int sum = 0;
    
    for(int i = 1; i <= n; ++i){
        v.push_back(i);
    }
    
    while(r < n && l < n){
        if(sum < n){
            r++;
            sum += v[r];
        }else if(sum > n){
            sum -= v[l];
            l++;
        }else{
            answer++;
            r++;
            sum += v[r];
        }
    }
    
    return answer;
}