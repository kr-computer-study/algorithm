#include <iostream>
#define MAX 16

using namespace std;

char Tree[MAX];

//전위 순회 함수!
void Preorder(int num)
{
	if (num >= MAX||Tree[num]==0) return;
	cout << Tree[num] << " ";
	Preorder(num * 2);
	Preorder(num * 2 + 1);
}
/*
전위 순회의 우선순위는
1.root
2.left
3.right
*/

//중위 순회 함수!
void Inorder(int num)
{
	if (num >= MAX || Tree[num] == 0) return;
	Inorder(num * 2);
	cout << Tree[num] << " ";
	Inorder(num * 2 + 1);
}
/*
중위 순회의 우선순위는
1.left
2.root
3.right
*/

//후위 순회 함수!
void Postorder(int num)
{
	if (num >= MAX || Tree[num] == 0) return;
	Postorder(num * 2);
	Postorder(num * 2 + 1);
	cout << Tree[num] << " ";
}
/*
위 순회의 우선순위는
1.left
2.root
3.right
*/

/*
num*2는 왼쪽 노드를 의미하고
num*2+1은 오른쪽 노드를 의미한다.
만일 MAX와 같거나 크다면 이는 배열의
노드 밖이라는 것을 의미한다.
*/
int main() {

	Tree[1] = 'A';
	Tree[2] = 'B';
	Tree[3] = 'C';
	Tree[4] = 'D';
	Tree[5] = 'E';
	Tree[6] = 'F';
	Tree[7] = 'G';
	Tree[8] = 'H';
	Tree[9] = 'I';
	Tree[10] = 'J';
	Tree[11] = 'K';
	Tree[12] = 'L';
	Tree[13] = 0;
	Tree[14] = 0;
	Tree[15] = 0;
	//문자형 Tree배열의 1번 ~15번 인덱스에 A~O를 넣어준다.

	cout << "전위 순회 결과 : ";
	Preorder(1);
	cout << endl;

	cout << "중위 순회 결과 : ";
	Inorder(1);
	cout << endl;

	cout << "후위 순회 결과 : ";
	Postorder(1);
	cout << endl;
}
