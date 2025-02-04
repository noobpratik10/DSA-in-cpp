#include <iostream>
using namespace std;

class node
{
private:
    int data;

public:
    class node *left;
    class node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    int getData()
    {
        return this->data;
    }
};

// preorder traversal
void preOrderTraversal(class node *root)
{
    if (root != NULL)
    {
        cout << root->getData() << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// postOrderTraversal
void postOrderTraversal(class node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->getData() << endl;
        return;
    }
}

// inOrder Traversal
void inOrderTraversal(class node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->getData() << endl;
        inOrderTraversal(root->right);
    }
}
// create binary search tree eample
//       9
//     /   \
//    4     11
//   /\    /  \ 
//  2  8  10   12

int main()
{
    // creating new nodes
    class node *root = new node(9);
    root->left = new node(4);
    root->right = new node(11);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->right->left = new node(10);
    root->right->right = new node(12);

    // inOrder Traversal
    cout << "in Order Traversal of the tree is:" << endl;
    inOrderTraversal(root);
    return 0;
}