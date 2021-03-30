#include <iostream>
#include <vector>
#include <string>

using namespace std;

//최대 캔디를 몇개를 먹을수 있을지 탐색하는 함수
int candyresult(vector<string> candy,int s)
{
	//가로 먼저 탐색한다.
	int columnresult = 1;
	int middleresult = 1;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s-1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				middleresult++;
				//j와 j+1번 째가 같을수록 중간 카운트함수
				//middleresult를 ++시켜준다.
				//최근의 최대값보다 크다면 이 값을 최종값을해준다.
				if (middleresult > columnresult) {
					columnresult = middleresult;
				}
			}
			else
			{
				middleresult = 1;
			}
		}
		middleresult = 1;//한 라인이 넘어가면 더이상 카운트를 하짐 못한다.
										//다른 문자인데 중복으로 카운트 될 수있기 때문.
	}

//위와 같은 방식이다. 탐색이 좌우에서 상하로만 바뀌었다.
	int rowresult = 1;
	middleresult = 1;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				middleresult++;
				if (middleresult > rowresult)
					rowresult = middleresult;
			}
			else
			{
				middleresult = 1;
			}
		}
		middleresult = 1;
	}

	return max(columnresult,rowresult);
}
int main()
{

	int N;
	cin >> N;
	vector<string> Bomboni;
	string cmd;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		Bomboni.push_back(cmd);
	}
//문자열을 vector에 받아준다.

//가로가 바뀌는 경우부터 탐색하준다.
	int colanswer=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (Bomboni[i][j] != Bomboni[i][j + 1]) {
				swap(Bomboni[i][j], Bomboni[i][j + 1]);//문자열 위치를 잠시 바꿔주고 탐색!
				int c = candyresult(Bomboni, N);
				if (c > colanswer)//c를 중간함수로 두고 최대값을 colanswer로 업데이트
					colanswer = c;
					swap(Bomboni[i][j], Bomboni[i][j + 1]);//다시 자리 바꿔줘야 함!
			}
		}
	}

	int rowanswer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (Bomboni[j][i] != Bomboni[j + 1][i]) {
				swap(Bomboni[j][i], Bomboni[j + 1][i]);
				int r = candyresult(Bomboni, N);
				if (r > rowanswer)
					rowanswer = r;
				swap(Bomboni[j][i], Bomboni[j + 1][i]);
//위와 같은 방식으로 진행
			}
		}
	}
	cout << max(colanswer, rowanswer) << endl;
	//가로값을 바꾼 경우, 세로값으로 바꾼 경우의 최대값들의 최대값을 출력한다!
}
