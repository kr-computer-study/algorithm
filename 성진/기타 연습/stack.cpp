#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
/*
LIFO (Last In First Out) 구조 : 한 쪽 끝에서만 자료를 넣고 뺄 수 있는 구조
*/
int main()
{
	stack<int> st({10,9,8,7,6});

	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	//스택에 값 추가!

	cout << st.top() << endl;
	//스택의 가장 위의 원소의 값 반환!

	st.pop();
	//스택의 가장 위의 값을 pop!

	cout << st.size() << endl;
	//스택의 크기 반환

	cout << st.empty() << endl;
	//스택이 비어있으면 true 아니면 false를 반환
}
