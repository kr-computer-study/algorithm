#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int result = 0;

void DFS(vector<int> dd[], int start, bool cc[])
{
	cc[start] = true;


	for (int i = 0; i < dd[start].size(); i++)
	{

			int x = dd[start][i];
			if (cc[x] == false) {
			DFS(dd, x, cc);
			result++;
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

	bool* dfscheck = new bool[N + 1]{ false, };
	DFS(node, 1, dfscheck);
	cout << result << endl;
}
