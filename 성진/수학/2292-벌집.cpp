#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long rangea=1,rangeb=1;
	long long result =1;
	while (true)
	{
		if (rangea <= n && n <= rangeb)
		{
			cout << result << endl;
			break;
		}
		rangea += 1;
		rangeb += 6 * result;
		result++;
	}
}
