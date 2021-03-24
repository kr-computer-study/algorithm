#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Editor
{
	char ch;
	Editor* pre;
	Editor* nex;
};
//이중 연결 리스트의 구조체 선언
//이전 노드 하나, 다음노드 하나

Editor head, tail;
Editor *listadress;
//머리와 꼬리는 데이터가 들어있지 않다.
//현재 진행의 다음 노드의 주소를 담은 포인터도 하나 지정해준다.

int main(void) {

	head.nex = &tail;
	tail.nex = NULL;
	head.pre = NULL;
	tail.pre = &head;
	listadress = &tail;
//기본 사용 설정 셋팅을 한다!


	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		Editor* listeditor = new Editor;
		listeditor->ch = str[i];

		listeditor->nex = listadress;
		listeditor->pre = listadress->pre;
		listadress->pre->nex = listeditor;
		listadress->pre = listeditor;
	}
/*
입력받은 초기 문자열의 길이만큼 리스트를 생성해준다.
새로운 리스트의 데이터는 문자,
다음 노드는 포인터listadress,
이전 노드는 listadress의 이전 노드,
그리고 listadress의 정보를 다시 선언해준다.
*/

	int repeat;
	cin >> repeat;

	char cmd;
	for (int i = 0; i < repeat; i++)
	{
		cin >> cmd;

		if (cmd == 'L') {
			if (listadress->pre->pre!=NULL)
				listadress = listadress->pre;
		}
		//listadress의 주소값을 이전 노드로 바꾼다.

		if (cmd == 'D') {
			if (listadress->nex != NULL)
				listadress = listadress->nex;
		}
		//listadress의 주소값을 다음 노드로 바꾼다.

		if (cmd == 'B') {
			if (listadress->pre != &head)
			{
				auto it = listadress->pre;
				listadress->pre->pre->nex = listadress;
				listadress->pre = listadress->pre->pre;
				delete it;
			}
		}
		//listadress의 이전의 이전의 다음 노드는 listadress이다.
		//listadress의 새로운 이전 노드는 listadress의 이전의 이전노드이다.

		if (cmd == 'P') {
			char PP;
			cin >> PP;
			Editor* listeditor = new Editor;
			listeditor->ch = PP;

			listeditor->nex = listadress;
			listeditor->pre = listadress->pre;
			listadress->pre->nex = listeditor;
			listadress->pre = listeditor;
			//초기문자열의 입력과 같이 한다.
		}
	}


	Editor* start = &head;
	start = start->nex;
//값을 왔다갔다 할 새로운 노드를 하나 선언해준다.
	while (start->nex!=NULL)
	{
		cout << start->ch;
		start = start->nex;
	}
	//주소를 다음 주소로 하나씩 옮겨가며 안의 데이터를 뽑아준다.
}
