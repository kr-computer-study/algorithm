#include <iostream>

using namespace std;

int cnt = 0;
int chessboard[15];
int boardsize;

bool check(int x,int y)
{
	for (int a = 0; a < x; a++) {
		if (chessboard[a] == y || x - a == abs(y - chessboard[a]))
			return 0;
	}
	return 1;
}
//현재 열까지 반복하여 값이 같거나, 혹은 대각선에 있다면 놓을 수 없다!
//현재 루트를 포기한다.
void n_queen(int n)
{
	if (n == boardsize) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < boardsize; i++)
		{
			chessboard[n] = i;
			if (check(n,i))
				n_queen(n + 1);
		}
	}
}
//반복문은 입력받은 사이즈-1 까지 탐색하므로
//현재 n값이 입력한 사이즈와 같다면 성공! 카운트를 늘려준다.
//아니라면 보드사이즈만큼 0부터 반복문을 돌며 루트를 찾는다.
int main() {
	cin >> boardsize;
	n_queen(0);
	cout << cnt << endl;
}
