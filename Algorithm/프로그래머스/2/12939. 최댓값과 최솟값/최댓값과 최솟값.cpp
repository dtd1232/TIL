#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string inputStr = "";
    
    vector<int> v;
    
    int n = 0;
    string temp = "";
    
    while(true){
        if(n == s.length()){
            break;
        }
        if(s[n] == ' '){
            v.push_back(stoi(temp));
            temp = "";
            n++;
        }else{
            temp += s[n];
            n++;
        }
    }
    v.push_back(stoi(temp));
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + " " + to_string(v.back());
    
    return answer;
}