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

// recursive searching in bst
class node *search(class node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->getData() == key)
        {
            return root;
        }
        else if (root->getData() > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

// iterative searching in bst
class node *searchIter(class node *root, int key)
{

    while (root != NULL)
    {
        if (key == root->getData())
        {
            return root;
        }
        else if (key < root->getData())
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    // searching recursive/iterative
    int n = 12;
    // class node *ptr = search(root, n);
    class node *ptr = searchIter(root, n);
    if (ptr == NULL)
    {
        cout << n << " is not present in BST." << endl;
    }
    else
    {
        cout << n << " is present in BST." << endl;
    }

    // deleting the alloted memory
    delete root->left;
    delete root->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;

    return 0;
}