#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int paintcnt = 0;
int paintsize = 0;
int paintsizecnt = 0;
bool paint[500][500];
bool visit[500][500];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Search(int x,int y)
{
	paintsizecnt = 0;
	queue<pair<int, int>> BFS;
	BFS.push({ x,y });
	visit[x][y] = 1;

	while (!BFS.empty())
	{
		pair<int, int> tmp = BFS.front();
		BFS.pop();
		paintsizecnt++;
		for (int a = 0; a < 4; a++)
		{
			int tmpx = tmp.first + dx[a];
			int tmpy = tmp.second + dy[a];
			if (tmpx < 0 || tmpy < 0 || tmpx >= n || tmpy >= m) continue;
			if (visit[tmpx][tmpy] == 1 || paint[tmpx][tmpy] == 0) continue;
			visit[tmpx][tmpy] = true;
			BFS.push({ tmpx,tmpy });
		}
	}
	if (paintsizecnt > paintsize)
		paintsize = paintsizecnt;
}
int main()
{
	cin >> n >> m;

	bool input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			paint[i][j] = input;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paint[i][j] == 0 || visit[i][j] == 1)
				continue;
			Search(i,j);
			paintcnt++;
		}
	}

	cout << paintcnt<<"\n"<<paintsize;
}
