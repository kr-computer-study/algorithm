/*
	문자열 뺄셈 방법이다.

	첫째 수가 무조건 크다는 조건하에 연산 방법은 간단하다.

	내림수(borrow)가 필요한 경우가 아니면 자릿수끼리 빼주기만 하면 된다. 
	
	내림수 로직은 자릿수보다 하나 높은 수를 하나 가져와 자릿수에 10을 더해주면 된다.
	
	내림수가 필요한 경우는 윗 수의 자릿수보다 아랫 수의 자릿수가 높은 경우이다.

	이 로직에 맞춰 1의 자릿수부터 연산을 반복한다.

	--- 실행 결과 ---
	Input UP : 1004
	Input DN : 8

	   0 0 0 0 0 0 0 0 0 0 0 1 0 0 4
	-  0 0 0 0 0 0 0 0 0 0 0 0 0 0 8
	--------------------------------
	=  0 0 0 0 0 0 0 0 0 0 0 0 9 9 6

	--- 실행 결과 ---
	Input UP : 141141141141
	Input DN : 414

	   0 0 0 1 4 1 1 4 1 1 4 1 1 4 1
	-  0 0 0 0 0 0 0 0 0 0 0 0 4 1 4
	--------------------------------
	=  0 0 0 1 4 1 1 4 1 1 4 0 7 2 7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 15				// 문자열 최대 길이

// 문자열 글자 '0' 으로 초기화
void strin(char arg[MAX]) {
	int a;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';		// 문자열 글자 '0'으로 초기화
	}
}

// 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
void strmvstr(char arg[MAX], int len) {
	int a;
	char temp[MAX] = { 0, };

	strin(temp);		// temp 문자열 글자 '0'으로 초기화

	for (a = 0; a < len; a++) {
		temp[(MAX - len) + a] = arg[a];	// 좌측정렬
	}

	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0, b = 0;
	char up[MAX] = { 0, };
	char down[MAX] = { 0, };
	char result[MAX] = { 0, };

	strin(up);
	strin(down);

	printf(" Input UP : ");
	scanf("%s", up);

	printf(" Input DN : ");
	scanf("%s", down);

	printf("\n  ");
	strmvstr(up, strlen(up)); // 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) printf(" %c", up[a]);

	printf("\n- ");
	strmvstr(down, strlen(down)); // 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) printf(" %c", down[a]);

	printf("\n--------------------------------\n");

	for (a = MAX-1; a > 0; a--) {
		if (up[a] < down[a]) {
			up[a] += 10;
			up[a-1]--;
		}

		result[a] = up[a] - down[a];
	}

	printf("= ");
	for (a = 0; a < MAX; a++) printf(" %d", result[a]);		// 뺄셈 결과 확인
}