#include <stdio.h>

int indexNum[4][6] = { {3,1,0,5,4,2},{2,1,5,0,4,3},{1,5,2,3,0,4},{4,0,2,3,5,1} };
int nowindex[6] = { 0,1,2,3,4,5 };
int tmpindex[6] = { 0 };
int dice[6] = { 0 };
int maps[20][20];
int nx[4] = { 0,0,-1,1 }; //동 서 북 남
int ny[4] = { 1,-1,0,0 };
int n, m;
int x, y, k;

int out(int x, int y) { //maps 나간지 확인
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 1;
	else return 0;
}

int dice_f(int d) {
	int dr = d - 1;
	if (out(x+nx[dr],y+ny[dr]))
		return 0;
	x += nx[dr];
	y += ny[dr];
	
	for (int i = 0; i < 6; i++)
	{
		tmpindex[i] = nowindex[i];
	}
	for (int i = 0; i < 6; i++)
	{
		nowindex[i] = tmpindex[indexNum[dr][i]];
	}
	
	if (maps[x][y] == 0) { //이동한 칸에 쓰여 있는 수가 0이면
		maps[x][y] = dice[nowindex[0]];
	}
	else {
		dice[nowindex[0]] = maps[x][y];
		maps[x][y] = 0;
	}
	printf("%d\n", dice[nowindex[5]]);
	return 1;
}

int main() {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}
	int D;
	
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &D);
		dice_f(D);
	}


	return 0;
}