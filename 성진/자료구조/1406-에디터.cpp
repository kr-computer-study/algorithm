#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	stack<char> editora;
	stack<char> editorb;
	//커서를 기준으로 왼쪽은 editora스택,오른쪽은 editorb스택

	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
		editora.push(str[i]);
	//초기 문자열을 입력받고 한글자씩 editora에 push 한다.

	int repeat;
	cin >> repeat;
	//몇번 반복할래?

	char cmd;
	for (int i = 0; i < repeat; i++)
	{
		cin >> cmd;

		if (cmd == 'L') {
			if (!editora.empty())
			{
				editorb.push(editora.top());
				editora.pop();
			}
		}
		//커서를 왼쪽으로 옮기는 경우 왼쪽 문자를 하나 빼서 오른쪽에 넣는다.
		if (cmd == 'D') {
			if (!editorb.empty())
			{
				editora.push(editorb.top());
				editorb.pop();
			}
		}
		//커서를 오른쪽으로 옮기는 경우 오른쪽 문자를 하나 빼서 왼쪽에 넣는다.

		if (cmd == 'B') {
			if(!editora.empty())
			editora.pop();
		}
		//왼쪽의 문자를 지우는 것이므로 editora에서 pop한다!

		if (cmd == 'P') {
			char PP;
			cin >> PP;
			editora.push(PP);
		}
		//마찬가지로 왼쪽의 문자를 추가하는 것이니 editora 에 push한다
	}

	while (!editora.empty())
	{
		editorb.push(editora.top());
		editora.pop();
	}
	while (!editorb.empty())
	{
		cout << editorb.top();
		editorb.pop();
	}
	/*
	editora에서 하나씩 꺼내서 전부 editorb에 넣는다!
	그럼 역순으로 모두 editorb에 들어가는데,
	다시 editorb의 값을 pop하면서 출력하면 결과가 출력된다!
	*/
}
