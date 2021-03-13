/*
	문자열 곱셈 방법이다.

	'양수' 가 입력된다는 조건하에 연산 방법은 간단하다.

	2중 for 문을 이용해 곱셈을 간단히 나타날 수 있다.

	먼저 두 수(윗 수, 아랫 수) 를 입력 받는다. 

	아랫 수의 첫 번째 자릿수(1의 자리)를 기준으로 하여 윗수의 값들을 곱한 결과를 저장한다.

	저장할 때 아랫 수 index와 윗 수 index를 고려하여 저장해준다.

	곱셈이 한 번 끝나고 결과에 대해 올림수 계산을 해준다.

	기준 값을 하나 올린다. = 아랫수의 자릿수를 올린다. ( a--, 좌측 정렬을 했기 때문에 배열의 왼쪽을 top으로 본다. )

	를 반복한다.

	--- 실행 결과 ---
	Input UP : 48224
	Input DN : 3581

	   0 0 0 0 0 0 0 0 0 0 4 8 2 2 4	
	+  0 0 0 0 0 0 0 0 0 0 0 3 5 8 1
	--------------------------------
	=  0 0 0 0 0 0 1 7 2 6 9 0 1 4 4

	--- 실행 결과 ---
	 Input UP : 123
	 Input DN : 4

	   0 0 0 0 0 0 0 0 0 0 0 0 1 2 3
	+  0 0 0 0 0 0 0 0 0 0 0 0 0 0 4
	--------------------------------
	=  0 0 0 0 0 0 0 0 0 0 0 0 4 9 2
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

	printf("\n+ ");
	strmvstr(down, strlen(down)); // 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) printf(" %c", down[a]);

	printf("\n--------------------------------\n");
	
	for (a = MAX - 1; a > 0; a--) {	
		for (b = MAX - 1; b > 0; b--) {
			result[b-((MAX-1)-a)] += (up[b] - '0') * (down[a] - '0');
		}

		result[a - 1] += result[a] / 10;	// 올림수(Carry) 계산
		result[a] %= 10;
	}


	printf("= ");
	for (a = 0; a < MAX; a++) printf(" %d", result[a]);		// 덧셈 결과 확인
}