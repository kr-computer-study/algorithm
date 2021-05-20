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

	priority_queue<int> heap_max;

	int cmdrepeat;
	cin >> cmdrepeat;

	int cmd;

	for (int i = 0; i < cmdrepeat; i++)
	{
		cin >> cmd;
		if (cmd > 0)
			heap_max.push(cmd);
		else {
			if (heap_max.size() == 0) cout << "0" << "\n";
			else {
				cout << heap_max.top() << "\n";
				heap_max.pop();
			}
		}
	}
}
