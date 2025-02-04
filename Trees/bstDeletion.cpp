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

    void setData(int n)
    {
        this->data = n;
    }
    int getData()
    {
        return this->data;
    }
};

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

// inOrderPredeccessor finding function
class node *inOrderPredecessor(class node *root)
{

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// deletion
class node *deleteNode(class node *root, int key)
{
    // check whether the key is in the bst
    if (search(root, key) == NULL)
    {
        cout << key << " is not present in the BST." << endl;
        return NULL;
    }
    // declare inorderPredecessor
    class node *inPre;

    // deleting the iPre of initial root here after zeroing in on it
    if (root->left == NULL && root->right == NULL && root->getData() == key)
    {
        free(root);
        cout << "Node successfully deleted." << endl;
        return NULL;
    }

    // searching for the node to be deleted
    if (key < root->getData())
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->getData())
    {
        root->right = deleteNode(root->right, key);
    }

    // node found, now find its inPre and replace it by inPre
    // further do this until inPre becomes leaf node and then delete it.
    else
    {
        inPre = inOrderPredecessor(root);
        root->setData(inPre->getData());
        root->left = deleteNode(root->left, inPre->getData());
        // Why left?-> Bcoz in order predecessor always lies on left side of root.
    }
    return root;
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

    // deletion
    deleteNode(root, 2);

    // checking the deletio
    if (search(root, 2) == NULL)
    {
        cout << 2 << " is not present in BST." << endl;
    }
    else
    {
        cout << 2 << " is present in BST." << endl;
    }
    return 0;
}