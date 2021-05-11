#include <iostream>
#include <algorithm>
using namespace std;

int nminput[9];
int nm[9];
bool visit[9];
//숫자를 저장할 배열과 방문표시를 할 배열을 선언

void N_AND_M(int a, int b, int c)
{
	if (c == b+1) {
		for (int i = 1; i <=b; i++)
			cout << nm[i] << " ";
		cout << "\n";
		return;
	}
	//만일 M번까지 반복 후 M+1 차례라면 현재 배열의 수들을 탐색해준다.

	for (int i = 1; i <=a; i++) {//N까지 경우의 수 탐색
		if (visit[i] == false && nminput[i]>nm[c-1]) {//방문 되지 않은 경우에만
			nm[c] = nminput[i];
			visit[i] = true;//방문처리
			N_AND_M(a, b, c + 1);//다음 경우 탐색
			visit[i] = false;
			//이미 방문했던 경우는 다른 경우를 위해 false해준다.
		}
	}

}

//형식만 바뀌었다 똑같다.
int main()
{
	nminput[0] = -1;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		nminput[i] = x;
	}
	sort(nminput, nminput + N+1);

	N_AND_M(N, M, 1);
}
