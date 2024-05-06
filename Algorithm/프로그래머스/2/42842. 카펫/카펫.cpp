#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> commonDivisor;
    
    for(int i = 1; i <= yellow; ++i){
        if(yellow % i == 0){
            commonDivisor.push_back(i);
        }
    }
    
    for(int i = 0; i < commonDivisor.size(); ++i){
        int width = commonDivisor[i] + 2;
        int height = yellow / commonDivisor[i] + 2;
        if(width * height == brown + yellow){
            answer.push_back(height);
            answer.push_back(width);
            break;
        }
    }
    
    return answer;
}