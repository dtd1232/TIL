#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    
    v.push_back(0);
    v.push_back(1);
    
    for(int i = 2; i <= n; ++i){
        v[2] = v[0] + v[1];
        
        if(v[2] > 1234567){
            v[2] = v[2] % 1234567;
        }
        
        v[0] = v[1];
        v[1] = v[2];
    }
    
    answer = v[2];
    
    return answer;
}