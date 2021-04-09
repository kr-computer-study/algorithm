#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> array;

	string cmd;
	cin >> cmd;
	for (int i = 0; i < cmd.length(); i++)
		array.push_back(int(cmd[i]-'0'));

	sort(array.begin(), array.end(), greater<int>());

	for (int i = 0; i < array.size(); i++)
		cout << array[i];
}
