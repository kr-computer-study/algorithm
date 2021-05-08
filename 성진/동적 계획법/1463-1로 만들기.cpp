#include <iostream>
#include <vector>
using namespace std;

int dp[1000001] = { 0, };

int main()
{
	int number;
	cin >> number;

	//1경우는 0회로 고정시키고 2회부터 경우의 수를 채운다!
	for (int i = 2; i <= number; i++)
	{
		dp[i] = dp[i - 1] + 1;
		//규칙 3부터 진행한다. 1을 빼는 연산
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		//2로 나누는 연산, 이전 규칙 에서 연산한 결과와 비교하여 적은 값을 넣는다.
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		//3으로 나누는 연산, 이전 규칙 에서 연산한 결과와 비교하여 적은 값을 넣는다.
	}
	cout << dp[number] << endl;
}
