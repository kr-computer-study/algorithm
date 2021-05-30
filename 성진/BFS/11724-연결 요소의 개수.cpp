#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int result = 0;

void BFS(vector<int> *vec,bool *vis,int num) {

	queue<int> qqq;
	qqq.push(num);

	vis[num] = true;

	while (!qqq.empty())
	{
		int tmp = qqq.front();
		qqq.pop();
		for (int a = 0; a < vec[tmp].size(); a++)
		{
			int b = vec[tmp][a];
			if (vis[b] == false)
				qqq.push(b);
			vis[b] = true;
		}
	}
}

int main(){

	int N, M;
	cin >> N >> M;
	vector<int> *Graph=new vector<int>[N+1];
	bool* visit = new bool[N + 1] {false,};

	int x, y;
	for (int  i = 0; i < M; i++)
	{
		cin >> x >> y;
		Graph[x].push_back(y);
		Graph[y].push_back(x);
	}
	for (int i = 1; i <=N ; i++)
	{
		if (visit[i] == true)
			continue;
		else {
			BFS(Graph, visit, i);
			result++;
		}

	}
	cout << result << endl;
}
