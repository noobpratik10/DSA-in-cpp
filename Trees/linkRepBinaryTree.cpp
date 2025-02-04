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

// create tree eample
//     12
//     /\
//    4  5
//   /\
//  2  8

int main()
{ // creating new nodes
    class node *root = new node(12);
    class node *n1 = new node(4);
    class node *n2 = new node(5);
    class node *n3 = new node(2);
    class node *n4 = new node(8);

    // linking the parent node with children
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    cout << "pre Order Traversal of tree" << endl;
    preOrderTraversal(root);
    cout << "post Order Traversal of tree" << endl;
    postOrderTraversal(root);
    cout << "in Order Traversal of tree" << endl;
    inOrderTraversal(root);
    cout << "level Order Traversal of tree" << endl;

    // deleting the alloted memory
    delete root;
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}
