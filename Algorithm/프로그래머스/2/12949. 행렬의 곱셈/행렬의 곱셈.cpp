#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tempVec;
    int temp = 0;
    
    for(int row = 0; row < arr1.size(); ++row){
        for(int row2 = 0; row2 < arr2[0].size(); ++row2){
            for(int col = 0; col < arr1[0].size(); ++col){
                temp += arr1[row][col]*arr2[col][row2];
            }
            tempVec.push_back(temp);
            temp = 0;
        }
        answer.push_back(tempVec);
        tempVec.clear();
    }
    
    return answer;
}