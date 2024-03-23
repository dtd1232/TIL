# BFS

---

## BJ_10026_적록색약
- 7주차에 시도했다가 실패했던 적록색약을 성공했다
- 당시에는 정상 그림, 색약 그림 2개를 만들고 각각 BFS를 돌리는 방법을 생각했는데, 너무 복잡해져서 포기했다
- 새롭게 생각한 알고리즘은 1개의 그림(2차원 배열)과 1개의 BFS 알고리즘을 사용한다
  - 먼저 원래 그림을 입력 받는다
  - 원래 그림을 BFS를 돌려서 구역의 수를 구한다 - 1
  - 원래 그림을 색약 그림으로 바꾼다
    - G 부분을 R로 바꾸는 반복문을 돌린다
    - 원래 R G B로 구성되어있던 그림이 R과 B로만 구성된다
  - 색약 그림을 BFS를 돌려서 구역의 수를 구한다 - 2
  - 1과 2를 출력한다
- 오랜만에 보니까 해법이 생각나는거 같아서 기분이 좋다. 나란 사람..어쩌면 생각보다 성장이 빠를지도?
```c++
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
char board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void clearVisited();
int BFS();

int main(){
	fastcpp;
	
	cin >> n;
	
	int abNormal = 0;
	int normal = 0;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < n; j++){
			board[i][j] = temp[j];
		}
	}
	
	normal = BFS();
	
	clearVisited();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 'G'){
				board[i][j] = 'R';
			}
		}
	}
	
	abNormal = BFS();
	
	cout << normal << " " << abNormal;
	
	return 0;
}

void clearVisited(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vis[i][j] = false;
		}
	}
}

int BFS(){
	int cnt = 0;
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(vis[x][y]){
				continue;
			}
			
			cnt++;
			// 탐색할 좌표 pair<X, Y>
			queue<pair<int, int> > q;
			vis[x][y] = 1;
			q.push(make_pair(x, y));
			
			while(!q.empty()){
				pair<int, int> cur = q.front(); q.pop();
				for(int i = 0; i < 4; i++){
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					// n*n 밖일 경우 continue
					if(nx < 0 || nx >= n || ny < 0 || ny >= n){
						continue;
					}
					// 이미 방문 또는 같은 색이 아닐 경우
					if(vis[nx][ny] == 1 || board[nx][ny] != board[x][y]){
						continue;
					}
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}
```