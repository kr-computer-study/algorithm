#include <stdio.h>

int N, L;
int maps[103][103];
int copyMaps[103][103] = { 0 };
int result = 0;

int out(int indexX,int indexY) { 
	if (indexX < 0 || indexX >= N || indexY < 0 || indexY >= N)
		return 1;
	else return 0;
}

int up(int indexX,int indexY,int how,int getLayer) { //고개를 들어서 위를 보라 그리하면 길이 보일 것이다.
	if (how == 0) {
		for (int i = 0; i < L; i++) { //호출 받은 경사와 뒤 경사 같지 않았거나 밖에 나갔거나 경사로가 있을 경우
			if (maps[indexX][indexY - i] != getLayer || out(indexX, indexY - i) || copyMaps[indexX][indexY - i])
				return 0;		
		}
		for (int i = 0; i < L; i++) {
			copyMaps[indexX][indexY - i] = 1;
		}
	}
	else if (how == 1) {
		for (int i = 0; i < L; i++) { //호출 받은 경사와 뒤 경사 같지 않았거나 밖에 나갔거나 경사로가 있을 경우
			if (maps[indexX-i][indexY] != getLayer || out(indexX-i, indexY) || copyMaps[indexX-i][indexY])
				return 0;
		}
		for (int i = 0; i < L; i++) {
			copyMaps[indexX-i][indexY] = 1;
		}
	}
	return 1;
}

int down(int indexX, int indexY, int how, int getLayer) { //고개를 내렸을 때 보이는 것은 무엇인가?

	if (how == 0) {
		for (int i = 1; i <= L; i++) {
			if (maps[indexX][indexY + i] != getLayer || out(indexX, indexY + i) || copyMaps[indexX][indexY + i])
				return 0;
		}
		for (int i = 1; i <= L; i++) {
			copyMaps[indexX][indexY + i] = 1;
		}
	}
	else if (how == 1) {
		for (int i = 1; i <= L; i++) { //호출 받은 경사와 뒤 경사 같지 않았거나 밖에 나갔거나 경사로가 있을 경우
			if (maps[indexX + i][indexY] != getLayer || out(indexX + i, indexY) || copyMaps[indexX+i][indexY])
				return 0;
		}
		for (int i = 1; i <= L; i++) {
			copyMaps[indexX + i][indexY] = 1;
		}
	}
	return 1;
}

void runway() {

	for (int i = 0; i < N; i++) //가로 먼저 하자
	{
		for (int j = 0; j < N; j++)
		{
			if (!out(i, j + 1)) {

				if (maps[i][j] + 1 < maps[i][j + 1] || maps[i][j] - 1 > maps[i][j + 1])
					break;
				if (maps[i][j]+1 == maps[i][j + 1])
					if (up(i, j, 0, maps[i][j]) == 0)
						break;
				if (maps[i][j]-1 == maps[i][j + 1])
					if (down(i, j, 0, maps[i][j]-1) == 0)
						break;
			}
	
			
			if (j == N - 1) {
				result++;
			}
				
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyMaps[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!out(j + 1, i)) {
				if (maps[j][i] + 1 < maps[j + 1][i] || maps[j][i] - 1 > maps[j + 1][i])
					break;
				if (maps[j][i] +1 == maps[j + 1][i])
					if (up(j, i, 1, maps[j][i]) == 0)
						break;
				if (maps[j][i] -1 == maps[j + 1][i])
					if (down(j, i, 1, maps[j][i] - 1) == 0)
						break;
			}
			if (j == N - 1) {
				result++;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0;  i < N;  i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}
	runway();
	
	printf("%d", result);
}