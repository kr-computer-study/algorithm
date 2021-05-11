#include <iostream>
#include <algorithm>
using namespace std;

int nminput[9];
int nm[9];
bool visit[9];
//숫자를 저장할 배열과 방문표시를 할 배열을 선언

void N_AND_M(int a, int b, int c)
{
	if (c == b) {
		for (int i = 0; i < b; i++)
			cout << nm[i] << " ";
		cout << "\n";
		return;
	}
	//만일 M번까지 반복 후 M+1 차례라면 현재 배열의 수들을 탐색해준다.

	for (int i = 0; i < a; i++) {//N까지 경우의 수 탐색
		if (visit[i] == false) {//방문 되지 않은 경우에만
			nm[c] = nminput[i];
			visit[i] = true;//방문처리
			N_AND_M(a, b, c + 1);//다음 경우 탐색
			visit[i] = false;
			//이미 방문했던 경우는 다른 경우를 위해 false해준다.
		}
	}

}
/*
달라진 부분은 거의 없다.!
입력받을 배열과 출력할 배열을 따로 지정해두고
입력받을 배열에 입력을 받고 정렬해준다음,
출력 배열에 순서대로 지정해주면 된다!!!
*/
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		nminput[i] = x;
	}
	sort(nminput, nminput + N);

	N_AND_M(N, M, 0);
}
