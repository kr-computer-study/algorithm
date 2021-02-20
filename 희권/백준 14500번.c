#include <stdio.h>
int max = 0;
int N, M;
int arr[503][503];

void first_poly() {
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j + 3 < M; j++) 
			if (max < arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3])
				max = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
	for (int i = 0; i + 3 < N; i++)
		for (int j = 0; j < M; j++)
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];

}
void second_poly() {
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			if (max < arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];			
}
void third_poly() {
	for (int i = 0; i + 2 < N; i++)
		for (int j = 0; j + 1 < M; j++) {//
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
		}
	for (int i = 0; i + 2 < N; i++)
		for (int j = 1; j < M; j++) {
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1];
		}
	for (int i = 1; i  < N; i++)
		for (int j = 0; j + 2 < M; j++) {
			if (max < arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2])
				max = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
			if (max < arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j])
				max = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j];
		}
	for (int i = 0; i+1 < N; i++) //세로
		for (int j = 0; j + 2 < M; j++) {
			if (max < arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2])
				max = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
			if (max < arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j])
				max = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
		}
}
void four_poly() {
	for(int i=0;i+2<N;i++)
		for (int j = 0; j+1 < M; j++) {
			if (max < arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (max < arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j])
				max = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j];
		}
	for (int i = 0; i+1 < N; i++) 
		for (int j = 0; j+2 < M; j++) {
			if (max < arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2])
				max = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (max < arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2])
				max = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
		}
}
void five_poly() {
	
	for (int i = 0; i+2 < N; i++)
		for (int j = 0; j+1 < M; j++)
			if (max <arr[i][j]+ arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j])
				max = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
	for (int i = 0; i + 2 < N; i++)
		for (int j = 1; j < M; j++)
			if (max < arr[i+1][j-1] + arr[i][j] + arr[i+1][j] + arr[i+2][j])
				max = arr[i + 1][j - 1] + arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
	for (int i = 1; i < N; i++)
		for (int j = 0; j + 2 < M; j++)
			if (max < arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i][j+2])
				max = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i][j + 2];
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 2 < M; j++)
			if (max < arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i][j+2])
				max = arr[i][j] + arr[i][j+1] + arr[i + 1][j + 1] + arr[i][j+2];
}

int main() {

	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	first_poly();
	second_poly();
	third_poly();
	four_poly();
	five_poly();
	printf("%d", max);
	return 0;
}