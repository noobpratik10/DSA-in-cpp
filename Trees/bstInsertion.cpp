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

// insertion
void insert(class node *root, int key)
{
    class node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->getData())
        {
            printf("Cannot insert %d, already in BST", key);
            return;
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
    class node *n = new node(key);
    if (key < prev->getData())
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
    cout << "Insertion done succesfully." << endl;
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

    // insertion
    insert(root, 78);

    // deleting the alloted memory
    delete root->left;
    delete root->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;

    return 0;
}