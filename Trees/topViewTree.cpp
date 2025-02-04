#include <iostream>
#include <vector>
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

// create tree eample
//     12
//     /\
//    4  5
//   /\
//  2  8

void topView(node *root)
{
    vector<int> view;

    class node *ptr = root;
    while (ptr != NULL)
    {
        view.insert(view.begin(), ptr->getData());
        ptr = ptr->left;
    }
    ptr = root->right;
    while (ptr != NULL)
    {
        view.push_back(ptr->getData());
        ptr = ptr->right;
    }

    for (int i = 0; i < view.size(); i++)
    {
        cout << view[i] << " ";
    }
    cout << endl;
}
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

    // topview getter
    topView(root);

    // deleting the alloted memory
    delete root;
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}