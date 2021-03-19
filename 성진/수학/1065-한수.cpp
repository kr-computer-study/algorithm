#include <iostream>
#include <string>

using namespace std;

int hansu(int n)
{
	if (1 <= n && n <= 99)
		return n;
	//1부터 99까지의 수는 모두 등차수열이므로 모두 추가해준다!
	int cnt = 0;
	for (int i = 100; i <= n; i++)//세자리의 경우 문자열을 슬라이싱한다!
	{
			string cmdstr = to_string(i);//문자열 변수 선언!
			for (int j = 0; j < 5; j++)
			{
				if (cmdstr[0] + j == cmdstr[1] && cmdstr[0] + j * 2 == cmdstr[2])
				{
					cnt++;
					break;
				}
				/*
				각 자리의 숫자의 합이 서로 5이상 차이 날 수는 없으니 4까지만 탐색!
				1.증가하는 등차수열일 경우
				2.감소하는 등차수열일경우
				*/
				if (cmdstr[0] - j == cmdstr[1] && cmdstr[0] - j * 2 == cmdstr[2])
				{
					cnt++;
					break;
				}
			}
	}
	return 99+cnt;
}
int main()
{
	int n;
	cin >> n;
	cout << hansu(n) << endl;
}
