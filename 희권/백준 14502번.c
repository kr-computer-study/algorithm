#include <stdio.h>
#include <stdlib.h>

int N, M;
int lab[8][8];
int tmplab[8][8];
int answer = 0;

int dx[4] = { 0,1,0,-1 }; //우하좌상
int dy[4] = { 1,0,-1,0 };

typedef struct {
	int x, y;
}element;

typedef struct {
	element queue[800];
	int front, rear;
}Queuetype;

element pop(Queuetype* q) {
	q->front += 1;
	return q->queue[q->front];
}

void push(Queuetype* q,element item) {
	q->rear += 1;
	q->queue[q->rear].x = item.x;
	q->queue[q->rear].y = item.y;
}

int empty(Queuetype* p) {
	return (p->front == p->rear);
}

void BFS() {

	int afterSpread[8][8];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			afterSpread[i][j] = tmplab[i][j];

	Queuetype q;
	element loc;
	q.front = 0; q.rear = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (afterSpread[i][j] == 2) {
				loc.x = i;
				loc.y = j;
				push(&q, loc);
			}
	while (!empty(&q)) {
		loc = pop(&q);
		int x = loc.x;
		int y = loc.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= ny && ny < M && 0 <= nx && nx < N) {
				if (afterSpread[nx][ny] == 0) {
					afterSpread[nx][ny] = 2;
					loc.x = nx, loc.y = ny;
					push(&q, loc);
				}
			}

		}
	}
	int empty = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (afterSpread[i][j] == 0)
				empty++;
	if (answer < empty)
		answer = empty;
}

void wall(int cnt) {
	if (cnt == 3) //벽을 세개 만들었으므로
	{
		BFS();
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tmplab[i][j] == 0)
			{
				tmplab[i][j] = 1; //마찬가지로 해당칸에 새우고
				wall(cnt + 1);
				tmplab[i][j] = 0; //다시 허문다

			}
}

int main() {
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &lab[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				for (int k = 0; k < N; k++)
					for (int l = 0; l < M; l++)
						tmplab[k][l] = lab[k][l];
				tmplab[i][j] = 1;
				wall(1);
				tmplab[i][j] = 0;
			}
		}
	}
	printf("%d", answer);

	return 0;
}
