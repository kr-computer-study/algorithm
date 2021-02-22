#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char element;

typedef struct Node {
	element data;
	struct Node* left, * right;
}Node;

Node* create_node(element a) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = a;
	tmp->left = tmp->right = NULL;
	return tmp;
}
Node* newNode(Node* root,element a,element b) {
	
	
	if (root->left == NULL&&a!='.') {
		root->left = create_node(a);
	}
	if (root->right == NULL&&b!= '.') {
		root->right = create_node(b);
	}
	return root;
}
Node* search_Node(Node* H, element ele)
{
	if (H != NULL) {
		if (H->data== ele) {
			return H;
		}
		else {
			Node* tmp = search_Node(H->left, ele);
			if (tmp != NULL) {
				return tmp;
			}

			return search_Node(H->right, ele);
		}
	}
	return NULL;
}

void fist_circuit(Node* root) {
	if (root != NULL) {
		printf("%c", root->data);
		fist_circuit(root->left);
		fist_circuit(root->right);
	}
}

void sec_circuit(Node* root) {
	if (root != NULL) {
		sec_circuit(root->left);
		printf("%c", root->data);
		sec_circuit(root->right);
	}
}
void th_circuit(Node* root) {
	if (root != NULL) {
		th_circuit(root->left);
		th_circuit(root->right);
		printf("%c", root->data);
	}
}
int main() {
	int N;
	scanf("%d", &N);
	element N_name1, N_name2, N_name3;
	scanf(" %c %c %c", &N_name1, &N_name2, &N_name3);

	Node* root = (Node*)malloc(sizeof(Node));
	root->data = N_name1;
	root->left = root->right = NULL;
	root=newNode(root, N_name2, N_name3);
	Node* tmp;
	for (int i = 0; i < N - 1; i++) {
		scanf(" %c %c %c", &N_name1, &N_name2, &N_name3);
		getchar();
		tmp = search_Node(root, N_name1);
		if (root != NULL)
			newNode(tmp, N_name2, N_name3);
		else
			newNode(root, N_name2, N_name3);
	}
	
	fist_circuit(root);
	printf("\n");
	sec_circuit(root);
	printf("\n");
	th_circuit(root);
	return 0;
}