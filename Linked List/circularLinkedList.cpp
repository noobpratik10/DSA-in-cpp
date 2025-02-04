#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};

// Traversal operation
void circularListTraversal(class Node *head)
{
    class Node *ptr = head;
    cout << "Elements of the circular Liked List are:-" << endl;
    do
    {
        cout << "Element:" << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}
// Insertion operation in circular linked list:-
// Case 1
class Node *insertAtHead(Node *head, int value)
{
    class Node *ptr = (class Node *)malloc(sizeof(class Node));
    ptr->data = value;

    Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);

    p->next = ptr;
    ptr->next = head;
    return ptr;
}
// Case 2
class Node *insertAtIndex(Node *head, int value, int index)
{
    class Node *ptr = (class Node *)malloc(sizeof(class Node));
    ptr->data = value;

    Node *p = head;
    int i = 0;
    do
    {
        p = p->next;
        i++;
    } while (i != index - 1);

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Deletion operation in circular Linked List
// Case 1
class Node *deleteAtHead(class Node *head)
{
    class Node *ptr = head;
    class Node *q = head->next;
    do
    {
        ptr = ptr->next;
        q = q->next;
    } while (q != head);
    ptr->next = q->next;
    free(q);
    return ptr->next;
}
// Case 2
class Node *deleteAtIndex(class Node *head, int index)
{
    class Node *ptr = head;
    class Node *q = head->next;
    int i = 0;
    do
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    } while (i != index - 1);
    ptr->next = q->next;
    free(q);
    return head;
}
int main()
{

    class Node *head = (class Node *)malloc(sizeof(class Node));
    class Node *second = (class Node *)malloc(sizeof(class Node));
    class Node *third = (class Node *)malloc(sizeof(class Node));
    class Node *fourth = (class Node *)malloc(sizeof(class Node));
    class Node *fifth = (class Node *)malloc(sizeof(class Node));

    head->data = 3;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 7;
    third->next = fourth;
    fourth->data = 9;
    fourth->next = head;

    circularListTraversal(head);
    // head=insertAtHead(head,67);
    // head=insertAtIndex(head,56,2);
    // head=deleteAtHead(head);
    // head=deleteAtIndex(head,2);
    circularListTraversal(head);

    return 0;
}