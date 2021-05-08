#include <iostream>
#include <vector>

using namespace std;

vector<long long> pp;

long long pibo(int n)
{
	if (n < pp.size())
		return pp[n];
	else {
		pp.push_back(pibo(n - 1) + pibo(n - 2));
		return pibo(n - 1) + pibo(n - 2);
	}
}
int main()
{
	pp.push_back(0);
	pp.push_back(1);

	int T;
	cin >> T;

	int number;
	for (int i = 0; i < T; i++) {
		cin >> number;
		if (number == 0)
			cout << "1 0" << "\n";
		else if (number == 1)
			cout << "0 1" << "\n";
		else
		cout << pibo(number-1)<<" "<<pibo(number)<<"\n";
	}
}
/*
0의 출력 횟수는 2번쨰부터 일반 피보나치 함수와 같고,
1의 출력횟수는 그냥 일반 피보나치 함수와 같다.
따라서, 동적 프로그래밍을 이용해 문젤르 풀이하면 된다!
*/
