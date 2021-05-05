#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int result = 0;

void BFS(vector<int> dd[], int start, bool cc[])
{
	queue<int> bfsq;
	bfsq.push(start);
	cc[start] = true;
	//큐를 하나 선언해주고 현재 노드를 넣어준다.
	//그리고 방문처리!
	while (!bfsq.empty())//큐가 빌 때까지 반복한다.
	{
		int x = bfsq.front();
		bfsq.pop();
		//큐의 맨 앞값을 출력해준다!
		for (int i = 0; i < dd[x].size(); i++)
		{//현재 벡터에 있는 원소들 중에서 방문이 안된 원소를 큐에 넣고 방문처리해준다.
			int y = dd[x][i];
			if (cc[y] == false)
			{
				bfsq.push(y);
				cc[y] = true;
				result++;//추가된 큐 마다 더해준다!
			}
		}
	}
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<int>* node = new vector<int>[N+1];
	//벡터를 이용해 N번 노드까지 표현해야되니 N+1로 선언해준다.

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	//각 노드에 맞게 값을 넣어준다.
	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}
	//값이 최소의 노드부터 탐색을 해야 하기 때문에
	//정렬해주어야 한다. 뒤죽박죽으로 탐색 할 수 있기 때문

	bool* bfscheck = new bool[N + 1]{ false, };
	BFS(node, 1, bfscheck);
	cout << result << endl;
}
