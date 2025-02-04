#include <iostream>
using namespace std;

/************* Linked List Insertion Types ***************/

class Node
{
public:
    int data;
    class Node *next;
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
// Case 1
class Node *insertAtFirst(Node *head, int value)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node));
    ptr->data = value;
    ptr->next = head;
    return ptr;
}
// Case 2
class Node *insertAtIndex(Node *head, int value, int index)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node *));
    ptr->data = value;
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Case 3
class Node *insetAtEnd(Node *head, int value)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node *));
    ptr->data = value;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Case 4
class Node *insertAfterValue(Node *head, int value, int data)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node *));
    ptr->data = data;
    Node *p = head;
    while (p->data != value)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Case 5
class Node *insertAfterNode(Node *head, Node *prevNode, int data)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node *));
    ptr->data = data;
    Node *p = head;
    while (p->next != prevNode->next)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{

    Node *head, *second, *third, *fourth;
    head = (class Node *)malloc(sizeof(class Node));
    second = (class Node *)malloc(sizeof(class Node));
    third = (class Node *)malloc(sizeof(class Node));
    fourth = (class Node *)malloc(sizeof(class Node));

    head->data = 7;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 8;
    fourth->next = NULL;

    linkedListTraversal(head);
    // head=insertAtFirst(head,6);
    // head=insertAtIndex(head,45,3);
    // head=insetAtEnd(head,67);
    // head=insertAfterValue(head,4,67);
    // head=insertAfterNode(head,third,45);
    linkedListTraversal(head);

    return 0;
}