#include <iostream>
#include <vector>

using namespace std;
/*
피보나치를 수열을 다이나믹으로 구하는 방법과 같은 방법이다.
피보나치가 n-1 + n-2 였다면, 이거는 n-1 , n-5의 방법이다.
대신에 미리 5번째까지의 값을 넣어줘야 한다.
*/
vector<long long> pado;

long long padoban(int n)
{
	if (n < pado.size())
		return pado[n];
	else {
		pado.push_back(padoban(n - 1) + padoban(n - 5));
		return padoban(n - 1) + padoban(n - 5);
	}
}
int main()
{
	pado.push_back(0);
	pado.push_back(1);
	pado.push_back(1);
	pado.push_back(1);
	pado.push_back(2);
	pado.push_back(2);

	int T;
	cin >> T;

	int number;
	for (int  i = 0; i < T; i++)
	{
		cin >> number;
		cout << padoban(number) << "\n";
	}
}
