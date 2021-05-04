#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int c1[7];
int c2[7];
vector<int>a[8];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	c1[start] = true;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		cout << x<<" ";
		for (int i = 0; i < a[x].size(); i++){
			int y=a[x][i];
			if (!c1[y]) {
				q.push(y);
				c1[y] = true;
			}
		}
	}
}
void DFS(int x)
{
	if (c2[x]) return;
	c2[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		DFS(y);
	}

}
int main()
{
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	cout << "BFS탐색 결과 : ";
	BFS(1);
	cout << endl;

	cout << "DFS탐색 결과 : ";
	DFS(1);
	cout << endl;
}
