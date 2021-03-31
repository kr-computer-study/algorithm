#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
private:
    Node* left;
    Node* right;
    Node* root;
public:
    T vaule;
    Node() : vaule('0'), left(nullptr), right(nullptr), root(nullptr) {};
    void SetLeft(Node* node) { this->left = node; }
    void SetRight(Node* node) { this->right = node; }
    Node* GetLeft() { return left; }
    Node* GetRight() { return right; }
    T GetValue() { return vaule; }
};
//클래스 템플릿을 이용해 포인터를 통한 트리 형태!


template <typename T>
void Preorder(Node<T>* node) //전위
{
    if (node == nullptr) return;
    cout << node->GetValue();
    Preorder(node->GetLeft());
    Preorder(node->GetRight());
}
/*
전위 순회의 우선순위는
1.root
2.left
3.right
*/
template <typename T>
void Inorder(Node<T>* node)//중위
{
    if (node == nullptr) return;
Inorder(node->GetLeft());
cout << node->GetValue();
Inorder(node->GetRight());
}
/*
중위 순회의 우선순위는
1.left
2.root
3.right
*/

template <typename T>
void Postorder(Node<T>* node) //후위
{
    if (node == nullptr) return;
    Postorder(node->GetLeft());
    Postorder(node->GetRight());
    cout << node->GetValue();
}
/*
위 순회의 우선순위는
1.left
2.root
3.right
*/


int main() {
    int nodenumber;
    cin >> nodenumber;

    Node<char>* Treenode = new Node<char>[nodenumber];
//사용자가 입력한 크기만큼 동적 배열을 할당해준다.
    for (int i = 0; i < nodenumber; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int nodename = a - 'A';
				//0번트리가 A,1번 B,로 연결되도록 설정해준다.
        Treenode[nodename].vaule = a;

         if (b != '.')
             Treenode[nodename].SetLeft(&Treenode[b-'A']);
         if (c != '.')
             Treenode[nodename].SetRight(&Treenode[c-'A']);
//그냥 설정
     }

    Preorder(&Treenode[0]);
    cout << endl;
    Inorder(&Treenode[0]);
    cout << endl;
    Postorder(&Treenode[0]);
    cout << endl;

    }
