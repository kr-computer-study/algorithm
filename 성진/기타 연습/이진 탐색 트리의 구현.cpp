#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


int findMin(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }
    else if (root->left == nullptr)
    {
        return root->data;
    }
    else
    {
        return findMin(root->left);
    }
}

int findMax(Node* root)
{

    if (root == nullptr)
    {
        return -1;
    }
    else if (root->right == nullptr)
    {
        return root->data;
    }
    else
    {
        return findMax(root->right);
    }
}

int findHeight(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return (left > right ? left : right) + 1;
}

int findNodes(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = findNodes(root->left);
    int right = findNodes(root->right);

    return left + right + 1;
}

Node* insert(Node* root, int data) {

    if (root == nullptr)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;

}

bool search(Node* root, int data)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

Node* root;

int main(int argc, const char* argv[]) {

    root = nullptr;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 29);


    if (search(root, 3) == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    int max = findMax(root);
    printf("max : %d\n", max);
    int min = findMin(root);
    printf("min : %d\n", min);
    int height = findHeight(root);
    printf("height : %d\n", height);
    int nodeCnt = findNodes(root);
    printf("node count : %d\n", nodeCnt);


    return 0;
}
