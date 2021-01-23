#include <stdio.h>

int isused[52][52] = { 0 }; //bool
int board[52][52];
int n, m; 
int X, Y, direction;
int clean_n = 0;
int dx[4] = { -1,0,1,0};
int dy[4] = { 0,1,0,-1}; //북 동 남 서

void robot_cleaner(int x,int y) {
	if (isused[x][y]==0) { //1. 청소한 곳이 아니라면 현재위치를 청소
		clean_n++;
		isused[x][y] = 1;
	}
	direction += 8;
	for (int i = 0; i < 4; i++) {
		direction -= 1; //현재 방향에서 왼쪽 방향으로 확인
		if (board[x + dx[direction % 4]][y + dy[direction % 4]] == 0 && board[x + dx[direction % 4]][y + dy[direction % 4]] != 1 && isused[x + dx[direction % 4]][y + dy[direction % 4]] == 0) {
			robot_cleaner(x + dx[direction % 4], y + dy[direction % 4]);//청소 안한 곳으로 이동
			return;
		}
	}
	// 만약 뒤에 벽이 없다면 후진
	if (board[x + dx[(direction - 2) % 4]][y + dy[(direction - 2) % 4]] != 1) 
		robot_cleaner(x + dx[(direction - 2) % 4], y + dy[(direction - 2) % 4]);

	return;
}

int main() {
	
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &X, &Y, &direction);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	robot_cleaner(X, Y);
	printf("%d", clean_n);

	return 0;
}