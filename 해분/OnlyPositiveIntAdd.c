/*
	문자열 덧셈 방법이다.

	자료형 크기에 제한(제약) 없이 연산 하자! 는 취지로 만들어진 기능같다.

	'양수'가 입력된다는 조건하에 연산 방법은 간단하다.

	배열에 수를 저장하면 왼쪽에서 차례대로 값을 저장한다. ( 좌측 정렬 )
	우리는 자릿수에 맞춰서 연산을 해야한다. 1의 자리는 1의 자리끼리, 10의 자리는 10의 자리끼리.
	
	해결 방법은 수를 입력받으면 오른쪽으로 다 밀어버리고 오른쪽에서 부터 연산을 시작한다. ( 우측 정렬 )

	두 입력값의 자릿수를 Sum 한다.
	Sum 결과에 의해 Carry 가 일어나면 앞 자릿수에 값을 올려준다.
	
	그러고 다음 자릿수를 연산한다.

	를 문자 길이만큼 반복한다.

	- 장점 -
	위에 취지와 같다. ( 자료형 크기에 제한이 없다. )
	때에 따라 자료형보다 메모리 사용량이 적을 수 있다.

	- 단점 -
	그 만큼 연산과정이 길다. ( 처리 시간 증가 )

	
	--- 실행 결과 ---
	Input UP : 123456
	Input DN : 456789012

	   0 0 0 0 0 0 0 0 0 1 2 3 4 5 6
	+  0 0 0 0 0 0 4 5 6 7 8 9 0 1 2
	--------------------------------
	=  0 0 0 0 0 0 4 5 6 9 1 2 4 6 8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 15				// 문자열 최대 길이 ( 15비트 만큼 쓸 겁니다 )

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
		temp[(MAX-len)+a] = arg[a];	// 좌측정렬
	}
	
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0;
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
	for (a = 0; a < MAX; a++) printf(" %c", up[a] );

	printf("\n+ ");
	strmvstr(down, strlen(down)); // 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) printf(" %c", down[a] );

	printf("\n--------------------------------\n");

	for (a = MAX - 1; a > 0; a--) {
		result[a - 1] = ( result[a] + (up[a] - '0' ) + ( down[a] - '0') ) / 10;	// 올림수(Carry) 계산
		result[a] = ( result[a] + (up[a] - '0' ) + ( down[a] - '0') ) % 10;
	}

	printf("= ");
	for (a = 0; a < MAX; a++) printf(" %d", result[a]);		// 덧셈 결과 확인
}