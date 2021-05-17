#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[90];

int main()
{
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 91; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
//점화식은 피보나치와 같다.
	cout << dp[n] << endl;
}
