#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int result=0;
		int N, M;
		cin >> N >> M;
		int cmd;
		priority_queue<int> printera;
		queue<pair<int, int>> printerb;
		for (int i = 0; i < N; i++)
		{
			cin >> cmd;
			printera.push(cmd);
			printerb.push(make_pair(i,cmd));

		}
		while (true)
		{
			int x = printerb.front().first;
			int y = printerb.front().second;
			printerb.pop();

			if (y == printera.top()) {
				printera.pop();
				result++;
				if (x == M) {
					cout << result << '\n';
					break;
				}
			}
			else {
				printerb.push({ x, y });
			}
		}

	}

}
