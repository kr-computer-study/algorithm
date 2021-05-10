#include <iostream>
using namespace std;

int nm[9];

void N_AND_M(int a, int b, int c)
{
	if (c == b + 1) {
		for (int i = 1; i <= b; i++)
			cout << nm[i] << " ";
		cout << "\n";
		return;
	}
	//만일 M번까지 반복 후 M+1 차례라면 현재 배열의 수들을 탐색해준다.

	for (int i = 1; i <= a; i++) {//N까지 경우의 수 탐색
			nm[c] = i;
			N_AND_M(a, b, c + 1);//다음 경우 탐색
		//방문표시를 할 필요가 없다!!!! 그냥 싹 다 날려주면 된다!
	}

}

int main()
{
	int N, M;
	cin >> N >> M;
	N_AND_M(N, M, 1);
}