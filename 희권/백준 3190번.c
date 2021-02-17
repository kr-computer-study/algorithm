#include <stdio.h>
#include <string.h>
#define Max_queue 10000

int Time = 0;
int maps[103][103] = { 0 }; //j가 x임
int dx[4] = { 0,1,0,-1 }; //우 하 좌 상 이건 i고
int dy[4] = { 1,0,-1,0 }; //이건 j임
typedef struct{
	int x;
	int y;
}coordinate;

typedef struct {
	int count;
	char dir;
}DIR;

int front = 0;
int rear = 0;
coordinate queue[Max_queue+3]; //뱀 몸통

void push_front(int get_x,int get_y) {
	queue[front].x = get_x;
	queue[front].y = get_y;
	maps[get_x][get_y] = 1;
	front = (front - 1 + Max_queue) % Max_queue;
}

void pop_back() {
	int prev = rear;
	
	rear = (rear - 1 + Max_queue) % Max_queue;
	maps[queue[prev].x][queue[prev].y] = 0;
}

void end() {
	printf("%d", Time+1);
}
int check_meet(int x, int y) { //벽에 닿았거나 몸에 닿았는가?
	if (x < 0 || y < 0 || maps[x][y] == 2||maps[x][y]==1)
		return 1;
	else return 0;
}
int main() {
	
	DIR dir[Max_queue + 3];
	int N, K, L;
	scanf("%d", &N);
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= N+1; j++) {
			if (i == N+1 || j == N+1||i==0||j==0)
				maps[i][j] = 2; //벽 생성
		}
	}
	scanf("%d", &K);
	int x, y;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x,&y);
		maps[x][y] = 3; //apple이 있는 곳은 3임
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &dir[i].count, &dir[i].dir);
	} 
	push_front(1, 1);
	// 우 하 좌 상
	int now_dir = 0;
	int now_x = 1;
	int now_y = 1;
	int L_count = 0;
	while (1) {
		if (dir[L_count].count == Time) {
			if (dir[L_count].dir == 'D')
				now_dir = (now_dir + 1) % 4;
			else if (dir[L_count].dir == 'L')
				now_dir = (now_dir - 1 + 4) % 4;
			L_count++;
		}
		if (check_meet(now_x + dx[now_dir], now_y + dy[now_dir])) {
				end();
				return 0;
		}
		Time++;
		if (maps[now_x + dx[now_dir]][now_y + dy[now_dir]] == 3)
				push_front(now_x + dx[now_dir], now_y + dy[now_dir]);
		else {
			push_front(now_x + dx[now_dir], now_y + dy[now_dir]);
			pop_back();
		}
		now_x += dx[now_dir];
		now_y += dy[now_dir];
		
		
	}
	
	
	return 0;
}