#include <stdio.h>
#include <string.h>
#define Max_stack 1000001

int top_n = -1;
int get_n[Max_stack]; //받을 정수
int stack[Max_stack]; //stack 인데 인덱스값을 곁들인
int result[Max_stack] = { 0 }; //오큰수를 저장할 변수

void push(int item) {
	stack[++top_n] = item;
}

void pop() {
	stack[top_n--];
}

int empty() {
	if (top_n == -1)
		return 1;
	else return 0;
}

int top() {
	
	return stack[top_n];
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &get_n[i]);
	}
	push(0); //push두번 X하기 위함
	for (int i = 1; i < N; i++) {
		if (empty()) //만약 스택이 비어있다면 i를 푸시
			push(i);
		else while (!empty() && get_n[top()] < get_n[i]) {  //오큰값 찾을 때까지
			result[top()] = get_n[i];
			pop();
		}
		push(i);
	}
	while (!empty()) { //오큰값이 존재하지 않는 것들 i로 바꾸기
		result[top()] = -1;
		pop();
	}
	for (int i = 0; i < N; i++)
		printf("%d ", result[i]);
	return 0;
}