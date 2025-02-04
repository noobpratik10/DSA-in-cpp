#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertToBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        // right part me jana hai
        root->right = insertToBST(root->right, d);
    }
    else
    {
        // left part me jana hai
        root->left = insertToBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cin >> data;
    }
}

// in order traversal
//  L N R
void inOrderTraversal(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    // use recursion for the rest
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// pre order traversal
//  N L R
void preOrderTraversal(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    // use recursion for the rest
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// post order traversal
//  L R N
void postOrderTraversal(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    // use recursion for the rest
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// level order traversal  --->  (Breadth First Search bhi kehte)
// using seperator
void levelOrderTraversal(Node *root)
{

    // queue banao
    queue<Node *> q;
    q.push(root);
    q.push(NULL); //--->Level 0 ka seperator

    // queue empty hone tak traverse karo
    while (!q.empty())
    {

        Node *temp = q.front();
        // cout << temp->data << " ";
        q.pop();

        if (temp == NULL)
        { // purana level complete ho chuka hai
            cout << endl;
            if (!q.empty())
            { // queue still has some child Nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// minimum and maximum vlaues in the bst
Node *minValue(Node *root)
{
    // base case
    if (root->left == NULL)
    {
        return root;
    }

    root = minValue(root->left);
    return root;
}

Node *maxValue(Node *root)
{
    // base case
    if (root->right == NULL)
    {
        return root;
    }

    root = minValue(root->right);
    return root;
}

// deletion in BST
Node *deleteNode(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }

    if (root->data > val)
    {
        // left part me jao
        root->left = deleteNode(root->left, val);
    }
    else
    {
        // riight part me jao
        root->right = deleteNode(root->right, val);
    }

    return root;
}
int main()
{
    Node *root = NULL;
    cout << "Enter the input for making binary search tree:" << endl;
    takeInput(root);

    cout << "Level order traversal of the binary search tree is:" << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal of the tree:" << endl;
    inOrderTraversal(root);

    cout << endl
         << "minimum value of the BST is:" << endl;
    cout << minValue(root)->data << endl;

    cout << "maximum value of the BST is:" << endl;
    cout << maxValue(root)->data << endl;

    deleteNode(root, 21);

    cout << "Inorder traversal of the tree:" << endl;
    inOrderTraversal(root);

    return 0;
}