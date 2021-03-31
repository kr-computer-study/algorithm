#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
	T vaule;
	Node* left;
	Node* right;
	Node* root;
public:
	Node() : vaule(0), left(nullptr), right(nullptr), root(nullptr) {};
	Node(T _value) :vaule(_value), right(nullptr), root(nullptr) {};
	Node(T _value, Node* _left, Node* _right) : vaule(_value), left(_left), right(_right), root(nullptr)
	{
		if (nullptr != left)
			_left->root = this;
		if (nullptr != right)
			_right->root = this;
	};
	~Node() {};
	void SetLeft(Node* node) { this->left = node; }
	void SetRight(Node* node) { this->right = node; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	T GetValue() { return vaule; }
};
int main() {
	Node<int>* node1 = new Node<int>(1);
	Node<int>* node2 = new Node<int>(2);
	Node<int>* node3 = new Node<int>(3);
	Node<int>* node4 = new Node<int>(4, node1, node2);
	Node<int>* node5 = new Node<int>(5);
	Node<int>* node6 = new Node<int>(6);

	node1->SetLeft(node3);
	node1->SetRight(node5);
	node2->SetRight(node6);
}
/*
트리의 모양
    4
	 / \
  1   2
 / \   \
3   5   6
*/
