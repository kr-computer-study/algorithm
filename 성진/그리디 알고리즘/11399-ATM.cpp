#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<short> Ptime;

	int N,x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		Ptime.push_back(x);
	}

	sort(Ptime.begin(), Ptime.end());

	int result = 0;
	int now = 0;
	for (int i = 0; i < N; i++) {
		now += Ptime[i];
		result += now;
	}


	cout << result;
}
