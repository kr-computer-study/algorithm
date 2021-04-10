#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<pair<int, int>> xandy;
	int num;
	cin >> num;

	int a, b;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		xandy.push_back(make_pair(a, b));
	}

	sort(xandy.begin(), xandy.end());
//자동으로 첫번째 인자값이 같으면 두번째 인자값으로 비교한다!
	for (int i = 0; i < num; i++)
		cout << xandy[i].first << " " << xandy[i].second << "\n";
}
