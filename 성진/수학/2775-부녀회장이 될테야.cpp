#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> apt[15];
	//2차원 배열을 이용할 것이다!

	for (int i = 1; i <=14; i++)
		apt[0].push_back(i);
	//0층의 인원은 연산을 위해 미리 초기화 시켜놓는다.

	for (int i = 1; i <= 14;i++)
	{
		apt[i].push_back(1);
		//각 층의 1호의 인원은 1명으로 고정이다!

		for (int j = 1; j < 14; j++)
			apt[i].push_back(apt[i - 1][j] + apt[i][j - 1]);
		//입주할 인원의 수는 아래층의 인원 + 이전 방의 인원과 같다!
		//이를 위해 0층과 각층의 1호를 초기화 해준 것!
	}


	int tcase;
	cin >> tcase;

	for (int i = 0; i < tcase; i++)
	{
		int k, n;
		cin >> k >> n;
		cout << apt[k][n-1]<<endl;
	}
	//출력 씹가능~

}
