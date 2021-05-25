#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<long> Lansun;

bool Possible(long num) {
	long result = 0;
	for (int i = 0; i < K; i++)
		result += Lansun[i] / num;

	if (result >= N) return true;
	else return false;
}

int main() {
	cin >> K >> N;
	long x;
	long start = 1, end = 0;

	for (int i = 0; i < K; i++) {
		cin >> x;
		Lansun.push_back(x);
		if (x > end)end = x;
	}

	long mid, result = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (Possible(mid) == true) {
			if (result < mid)
				result = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << result;
}
