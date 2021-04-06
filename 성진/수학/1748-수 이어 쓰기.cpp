#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n < 10)
		cout << n << endl;
	else {
		long long cnt = to_string(n).length();
		long long result = 9;
		for (int i = 1; i <= cnt-1; i++) {
			result +=(i+1) * (9 * (pow(10,i)));
		}
		result -= ((pow(10, cnt) - 1) - n) * cnt;
		cout << result << endl;
	}
}
