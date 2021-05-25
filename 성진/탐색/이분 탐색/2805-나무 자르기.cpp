#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<long> TreeCut;

bool Possible(long num) {
	long result = 0;
	for (int i = 0; i < N; i++) {
		if (TreeCut[i] <= num)result +=0;
		else result += TreeCut[i] - num;
	}
	if (result >= M) return true;
	else return false;
}

int main() {
	cin >> N >> M;
	long x;
	long start = 1, end = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;
		TreeCut.push_back(x);
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