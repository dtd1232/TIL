#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int k = 0;

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){
            k++;
        }else{
            if(k > 0){
                k--;
            }else{
                return false;
            }
        }
    }

    return !k;
}