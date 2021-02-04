#include <stdio.h>

int N, L;
int board[102][102];
int check_n = 0;
int Last = 0;
int isused[102][102] = { 0 };

int ascent(int x,int i,int j) {
	int X = j - L;
	if (x < L) {
		return 0;	
	}	
	else {
		for (int z = j-1; z >= X; z--) {
			if (isused[i][z] == 1) {
				return 0;
			}
			isused[i][z] = 1;
		}
		return 1;
	}
	
}

int a(int x, int i, int j) {
	int X = i - L;
	if (x < L) {
		return 0;
	}
	else {
		for (int z = i - 1; z >= X; z--) {
			if (isused[z][j] == 1) {
				return 0;
			}
			isused[z][j] = 1;
		}
		return 1;
	}

}

int downhill_F(int x,int i,int j) {
	int X = j + L;
	for (int z = j; z < X; z++) {
		if (isused[i][z] == 1)
			return 0;
		isused[i][z] = 1;
	}
	return 1;
}

int d(int x, int i, int j) {
	int X = i + L;
	for (int z = i; z < X; z++) {
		if (isused[z][j] == 1)
			return 0;
		isused[z][j] = 1;
	}
	return 1;
}

void runway() {

	int before = 0;
	int count = 0;
	int downhill = 0;
	int downhill_n = 0;
	int check = 0;
	
	for (int i = 0; i < N; i++) { //가로 확인
		before = board[i][0];
		count = 0;
		downhill = 0;
		downhill_n = 0;
		check = 0;
		for (int j = 0; j < N; j++) {
			if (before == board[i][j]) //전과 같을 때
				count++;
			else if (before + 1 < board[i][j] || before - 1 > board[i][j]) //2이상 차이날 때
				break;
			else if (before + 1 == board[i][j]) { //오르막길
				if (ascent(count, i, j) == 1) { //1일 시 count =1 && isused에다가 체크함
					count = 1;
					before = board[i][j];
					check++;
					continue;
				}
				else break;
			}
			else if (downhill == 0 && before - 1 == board[i][j]) { //내리막길
				downhill = 1;
				count = 1;
			}
			else break;
			if (downhill == 1)
					if (count >= L) {
						if (downhill_F(L, i, j) == 0)//isused에다가 체크함
							break;
						downhill = 0;
						count = 0;
					}
			
			before = board[i][j];
			check++;
		}
		if (check == N && downhill == 0) {
			Last++;
		}		
	}

	for (int i = 0; i < N; i++) { //isused 초기화
		for (int j = 0; j < N; j++) {
			isused[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) { //세로 확인
		before = board[0][i];
		count = 0;
		downhill = 0;
		downhill_n = 0;
		check = 0;
		for (int j = 0; j < N; j++) {
			if (before == board[j][i]) //전과 같을 때
				count++;
			else if (before + 1 < board[j][i] || before - 1 > board[j][i]) //2이상 차이날 때
				break;
			else if (before + 1 == board[j][i]) { //오르막길
				if (a(count, j, i) == 1) { //1일 시 count =1 && isused에다가 체크함
					count = 1;
					before = board[j][i];
					check++;
					continue;
				}
				else break;
			}
			else if (downhill == 0 && before - 1 == board[j][i]) { //내리막길
				downhill = 1;
				count = 1;
			}
			else break;
			if (downhill == 1)
				if (count >= L) {
					if (d(L, j, i) == 0)//isused에다가 체크함
						break;
					downhill = 0;
					count = 0;
				}

			before = board[j][i];
			check++;
		}
		if (check == N && downhill == 0) {
			//printf("%d\n", i);
			Last++;
		}
	}

}

int main() {

	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	runway();
	printf("%d", Last);

	return 0;
}