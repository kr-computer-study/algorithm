#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int number;
	cin >> number;

	short upper[10001] = {0,};
	//모든 수를 벡터나 배열에 넣는 것은 메모리 초과로 이어진다!

	int x;
	for (int i = 0; i < number; i++) {
		cin >> x;
		upper[x]++;
	}
	//각 인덱스에 맞게 선언된 배열의 값을 증가시켜준다.
	for (int i = 1; i < 10001; i++) {
		if (upper[i] == 0)
			continue;
		for (int j = 0; j < upper[i]; j++) {
			cout << i << "\n";
		}
	}
}
