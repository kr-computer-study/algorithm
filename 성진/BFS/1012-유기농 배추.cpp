#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool farm[50][50];
bool visit[50][50];
int M, N, K;
int X, Y;

void Cleararr() {
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			farm[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
void Search(int a,int b)
{

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int> > Q;
	visit[a][b] = 1;
	Q.push({ a,b });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
			if (visit[nx][ny] || farm[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
			visit[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
			Q.push({ nx,ny });
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{

		cin >> M >> N >> K;
		for (int i = 0; i <K; i++)
		{
			cin >> X >> Y;
			farm[X][Y] = true;
		}
		int result = 0;

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (visit[i][j] == 1 || farm[i][j] == 0) continue;
				Search(i, j);
				result++;
			}
		}
		cout << result << endl;
		Cleararr();

	}

}
