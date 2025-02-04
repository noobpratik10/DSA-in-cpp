#include <iostream>
using namespace std;

class node
{
public:
    int data;
    class node *left;
    class node *right;
    int height;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int getHeight(class node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalanceFactor(class node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

// Example:-
//        x                                   y
//        /\        left rotation            / \ 
//     T1    y      -------------->         x   T3
//           /\           w.r.t y          / \   
//         T2   T3                       T1   T2
class node *leftRotate(class node *x)
{
    class node *y = x->right;
    class node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

// Example:-
//         y                                    x
//        / \        right rotation            / \ 
//       x   T3      -------------->         T1    y
//      / \          w.r.t y                      / \   
//    T1   T2                                   T2   T3
class node *rightRotate(class node *y)
{
    class node *x = y->left;
    class node *T2 = x->left;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

// AVL ROTATIONS
class node *insert(class node *n, int key)
{
    if (n == NULL)
    {
        class node *n = new node(key);
        return n;
    }
    if (key < n->data)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->data)
    {
        n->right = insert(n->right, key);
    }

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    int bf = getBalanceFactor(n);

    // Left Left Case
    if (bf > 1 && key < n->left->data)
    {
        return rightRotate(n);
    }

    // Right Right Case
    if (bf < -1 && key > n->right->data)
    {
        return leftRotate(n);
    }

    // Left Right Case
    if (bf > 1 && key > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    // Right Left Case'
    if (bf < -1 && key < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void preOrder(class node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    class node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}