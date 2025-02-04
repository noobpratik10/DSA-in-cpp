#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;

    // constructor
    Node(int value){
        this->data=value;
        this->next=NULL;
    }   
};



    void linkedListTraversal(class Node *head)
    {
    class Node *ptr = head;
    cout << "Elements of the linked list are:" << endl;
    while (ptr != NULL)
    {
        cout << "Element:" << ptr->data << endl;
        ptr = ptr->next;
    }
    }

int main()
{
    Node *head=new Node(5);
    Node *second=new Node(4);
    Node *third=new Node(3);
    Node *fourth=new Node(2);

    linkedListTraversal(head);
   

    return 0;
}
