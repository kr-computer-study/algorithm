/*
	���ڿ� ���� ����̴�.

	'���' �� �Էµȴٴ� �����Ͽ� ���� ����� �����ϴ�.

	2�� for ���� �̿��� ������ ������ ��Ÿ�� �� �ִ�.

	���� �� ��(�� ��, �Ʒ� ��) �� �Է� �޴´�. 

	�Ʒ� ���� ù ��° �ڸ���(1�� �ڸ�)�� �������� �Ͽ� ������ ������ ���� ����� �����Ѵ�.

	������ �� �Ʒ� �� index�� �� �� index�� ����Ͽ� �������ش�.

	������ �� �� ������ ����� ���� �ø��� ����� ���ش�.

	���� ���� �ϳ� �ø���. = �Ʒ����� �ڸ����� �ø���. ( a--, ���� ������ �߱� ������ �迭�� ������ top���� ����. )

	�� �ݺ��Ѵ�.

	--- ���� ��� ---
	Input UP : 48224
	Input DN : 3581

	   0 0 0 0 0 0 0 0 0 0 4 8 2 2 4	
	+  0 0 0 0 0 0 0 0 0 0 0 3 5 8 1
	--------------------------------
	=  0 0 0 0 0 0 1 7 2 6 9 0 1 4 4

	--- ���� ��� ---
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

	printf("\n+ ");
	strmvstr(down, strlen(down)); // �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
	for (a = 0; a < MAX; a++) printf(" %c", down[a]);

	printf("\n--------------------------------\n");
	
	for (a = MAX - 1; a > 0; a--) {	
		for (b = MAX - 1; b > 0; b--) {
			result[b-((MAX-1)-a)] += (up[b] - '0') * (down[a] - '0');
		}

		result[a - 1] += result[a] / 10;	// �ø���(Carry) ���
		result[a] %= 10;
	}


	printf("= ");
	for (a = 0; a < MAX; a++) printf(" %d", result[a]);		// ���� ��� Ȯ��
}