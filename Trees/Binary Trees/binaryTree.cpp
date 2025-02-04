#include <bits/stdc++.h>
using namespace std;

// structure of node
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// building a tree
node *buildTree(node *root)
{
    // node banao
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;
    root = new node(data);

    // Base case for recursion
    if (data == -1)
    {
        return NULL;
    }

    // baki ke node using recursion
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of" << data << endl;
    root->right = buildTree(root->right);

    // last me tree ka root return karo
    return root;
}

// level order traversal  --->  (Breadth First Search bhi kehte)
// using seperator
void levelOrderTraversal(node *root)
{

    // queue banao
    queue<node *> q;
    q.push(root);
    q.push(NULL); //--->Level 0 ka seperator

    // queue empty hone tak traverse karo
    while (!q.empty())
    {

        node *temp = q.front();
        // cout << temp->data << " ";
        q.pop();

        if (temp == NULL)
        { // purana level complete ho chuka hai
            cout << endl;
            if (!q.empty())
            { // queue still has some child nodes
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

// reverse level order traversal function -->(modify original using stack)
// Differences b/w normal & reverse level order are:
// 1) Instead of printinf node, we push the node in stack
// 2) Right subtree is visited before left subtree

void reverseLevelOrder(node *root)
{
    // queue & stack banao
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL); //--->Level 0 ka seperator

    // queue empty hone tak traverse karo
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        s.push(temp); //--->pushing node in stack

        if (temp == NULL)
        { // purana level complete ho chuka hai
            // cout << endl;
            if (!q.empty())
            { // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            // cout << temp->data << " "; --->yaha print nhi karna
            // right subtree visited before left subtree
            if (temp->right)
            {
                q.push(temp->right);
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }

    // now pop all nodes from the stack & print them
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

// in order traversal
//  L N R
void inOrderTraversal(node *root)
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
void preOrderTraversal(node *root)
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
void postOrderTraversal(node *root)
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

// building tree using level order
void buildFromLevelOrder(node *&root)
{

    queue<node *> q;
    cout << "Enter data for root:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node for: " << temp->data << endl;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter right node for: " << temp->data << endl;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Morris traversal
void morrisTraversal(node *root)
{
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            node *current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }

            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                cout << root->data << " ";
                current->right = root;
                root = root->left;
            }
        }
    }
}

int main()
{

    /*creating a tree
              1
          3       5
        7  11  17     */
    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // level order Traversal
    // 1 3 5 7 11 17
    cout << "Level order Traversal of tree:" << endl;
    levelOrderTraversal(root);

    // inOrderTraversal
    // 7 3 11 1 17 5
    cout << "In order Traversal of tree:" << endl;
    inOrderTraversal(root);

    // preOrderTraversal
    // 1 3 7 11 5 17
    cout << "Pre order Traversal of tree:" << endl;
    preOrderTraversal(root);

    // postOrderTraversal
    // 7 11 3 17 5 1
    cout << "Post order Traversal of tree:" << endl;
    postOrderTraversal(root);

    // build tree from level order traversal
    root = NULL;
    buildFromLevelOrder(root);
    // check build hua ki nhi
    cout << "Level order Traversal of tree:" << endl;
    levelOrderTraversal(root);

    // reverse level order traversal
    cout << "Reverse level order Traversal of tree:" << endl;
    reverseLevelOrder(root);

    // Morris traversal
    morrisTraversal(root);

    return 0;
}