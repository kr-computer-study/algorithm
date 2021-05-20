#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long, vector<long>, greater<long> > heap_min;

	int cmdrepeat;
	cin >> cmdrepeat;

	long cmd;

	for (int i = 0; i < cmdrepeat; i++)
	{
		cin >> cmd;
		if (cmd > 0)
			heap_min.push(cmd);
		else {
			if (heap_min.size() == 0) cout << "0" << "\n";
			else {
				cout << heap_min.top() << "\n";
				heap_min.pop();
			}
		}
	}
}
