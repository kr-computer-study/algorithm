/*
	���ڿ� ���� ����̴�.

	ù° ���� ������ ũ�ٴ� �����Ͽ� ���� ����� �����ϴ�.

	������(borrow)�� �ʿ��� ��찡 �ƴϸ� �ڸ������� ���ֱ⸸ �ϸ� �ȴ�. 
	
	������ ������ �ڸ������� �ϳ� ���� ���� �ϳ� ������ �ڸ����� 10�� �����ָ� �ȴ�.
	
	�������� �ʿ��� ���� �� ���� �ڸ������� �Ʒ� ���� �ڸ����� ���� ����̴�.

	�� ������ ���� 1�� �ڸ������� ������ �ݺ��Ѵ�.

	--- ���� ��� ---
	Input UP : 1004
	Input DN : 8

	   0 0 0 0 0 0 0 0 0 0 0 1 0 0 4
	-  0 0 0 0 0 0 0 0 0 0 0 0 0 0 8
	--------------------------------
	=  0 0 0 0 0 0 0 0 0 0 0 0 9 9 6

	--- ���� ��� ---
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
#define MAX 15				// ���ڿ� �ִ� ����

// ���ڿ� ���� '0' ���� �ʱ�ȭ
void strin(char arg[MAX]) {
	int a;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';		// ���ڿ� ���� '0'���� �ʱ�ȭ
	}
}

// �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
void strmvstr(char arg[MAX], int len) {
	int a;
	char temp[MAX] = { 0, };

	strin(temp);		// temp ���ڿ� ���� '0'���� �ʱ�ȭ

	for (a = 0; a < len; a++) {
		temp[(MAX - len) + a] = arg[a];	// ��������
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
	strmvstr(up, strlen(up)); // �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
	for (a = 0; a < MAX; a++) printf(" %c", up[a]);

	printf("\n- ");
	strmvstr(down, strlen(down)); // �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
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
	for (a = 0; a < MAX; a++) printf(" %d", result[a]);		// ���� ��� Ȯ��
}