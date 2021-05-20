#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>>pyo;

	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		pyo.push(x);
	}
	for (int i = 0; i < N*N-N; i++)
	{
		cin >> x;
		if (pyo.top() < x) {
			pyo.pop();
			pyo.push(x);
		}
	}
	cout << pyo.top();
}
