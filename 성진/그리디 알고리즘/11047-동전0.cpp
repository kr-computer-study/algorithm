#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> money;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		money.push_back(x);
	}
	int result=0;
	for (int i = N-1; i >=0; i--)
	{
		if (K == 0) break;
		result += K / money[i];
		K %= money[i];
	}
	cout << result << endl;
}
