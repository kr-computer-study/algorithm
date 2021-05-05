#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int mainnumber = 1;
	while (true)
	{
		if (num - mainnumber <= 0)
			break;

		num -= mainnumber;
		mainnumber++;
	}

	int first, second;
	first = mainnumber % 2 == 1 ? mainnumber - (num - 1) : 1 + (num - 1);
	second = mainnumber % 2 == 1 ? 1 + (num - 1) : mainnumber - (num - 1);

	cout << first << "/" << second;
}
