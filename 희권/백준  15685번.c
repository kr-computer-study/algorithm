#include <stdio.h>
#include <math.h>
int board[102][102] = { 0 };
//방향만 저장하면 문제를 풀 수 있음
// 방향만 바꾸면 끝이야!!!!!

int dx[4] = { 0,-1,0,1 }; //우 상 좌 하
int dy[4] = { 1,0,-1,0 };
int draction[1000];
int draction_n = 0;
int re_draction[1000];

void reverse(int n) { //방향을 역으로 돌리는 함수
	for (int i = 0, j = n; i < n; i++, j--) {
		   
		re_draction[i] = (draction[j - 1] + 2) % 4;
		re_draction[i] += 4;
		re_draction[i] = (re_draction[i] - 1) % 4;
	}
}

void dragon_curve(int x, int y, int d, int g) { //드래곤 커브

	draction_n = 0;
	board[x][y] = 1;
	board[x + dx[d]][y + dy[d]] = 1;
	x += dx[d];
	y += dy[d];
	draction[0] = d;
	draction_n++;

	int save_n = 0;
	for (int i = 0; i < g; i++) {
		save_n = draction_n;
		reverse(save_n);
		for (int j = 0; j < save_n; j++) {
			board[x + dx[re_draction[j]]][y + dy[re_draction[j]]] = 1;  //x,y 좌표는 계속 움직이며 1로 바꿈
			x += dx[re_draction[j]];
			y += dy[re_draction[j]];
			draction[draction_n] = re_draction[j];  //역으로 돌린 것을 방향으로 저장
			draction_n++;
		}
	}
}

int main() {

	int n;
	scanf("%d", &n);
	int x, y, d, g;
	int last = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		dragon_curve(y, x, d, g);
	}

	for (int i = 0; i < 102; i++) {  //사각형 만들어지면 1++
		for (int j = 0; j < 102; j++) {
			if (board[i][j]==1)
				if (board[i + 1][j]==1)
					if (board[i][j + 1]==1)
						if (board[i + 1][j + 1]==1)
							last++;

		}
	}
	printf("%d", last);

	return 0;
}