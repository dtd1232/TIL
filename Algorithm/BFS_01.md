## BFS

## BJ_1962_그림
- dx, dy라는 배열을 주고 현재 칸의 상하좌우를 탐색한다.
- 탐색하면서 큐에 있는 순서를 뺀다.
- 상하좌우 중에 색칠이 되어있는데 방문을 안한 칸이 있으면 큐에 좌표를 넣는다. -> 다음에 탐색할 목표
- 큐에 아무것도 없을때까지 while문 반복한다.
- 큐에 아무것도 없으면(하나의 연결된 구역을 다 탐색했을때) -> 맨 앞의 2중 for문으로 색칠이 되어있고, 방문을 안했던 좌표 탐색
```c++
#include <iostream>
#include <queue>

using namespace std;

int grid[501][501];
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
int mx = 0;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void BFS(int n, int m){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(vis[x][y] || grid[x][y] == 0){
				continue;
			}
			cnt++;
			
			queue<pair<int, int> > q;
			vis[x][y] = 1;
			q.push(make_pair(x, y));
			
			// 그림의 넓이
			int temp = 0;
			
			while(!q.empty()){
				temp++;
				pair<int, int> cur = q.front(); q.pop();
				
				for(int i = 0; i < 4; i++){
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					// n * m 밖의 범위일 경우 continue
					if(nx < 0 || nx >= n || ny < 0 || ny >= m){
						continue;
					}
					// 이미 방문 또는 색칠이 안되어있으면 continue
					if(vis[nx][ny] || grid[nx][ny] != 1){
						continue;
					}
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			mx = max(mx, temp);
		}
	}
}


int main(){
	fastcpp;
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	BFS(n, m);
	
	cout << cnt << "\n" << mx;
	
	return 0;
}
```

- BFS는 차갑다...
- 하지만 어느정도 패턴이랑 매커니즘이 반복되는 느낌은 있어서 조금만 더 숙달된다면 잘 풀 수 있을것 같다.
- 오늘도 성장한 나에게 치얼스~