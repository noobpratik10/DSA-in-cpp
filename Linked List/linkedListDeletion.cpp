#include <iostream>
using namespace std;

/************* Linked List Deletion Types ***************/

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
class Node *deletionAtFirst(class Node *head)
{
    Node *ptr = (class Node *)malloc(sizeof(class Node));
    ptr = head->next;
    free(head);
    return ptr;
}
// Case 2
class Node *deletionAtIndex(Node *head, int index)
{
    Node *p = head;
    Node *q = p->next;
    int i = 0;
    while (i != index - 1)
    {
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Case 3
class Node *deletionAtEnd(Node *head)
{
    Node *p = head;
    Node *q = p->next;
    int i = 0;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Case 4
class Node *deletionValue(Node *head, int value)
{
    Node *p = head;
    Node *q = p->next;
    int i = 0;
    while (q->data != value && q->next != NULL)
    {
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Case 5
class Node *deletionTillIndex(Node *head, int index)
{
    // Node *p=head;
    int i = 0;
    Node *q = head->next;
    free(head);
    while (i != index - 1)
    {
        Node *ptr = q;
        q = q->next;
        free(ptr);
    }

    return q;
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
    // head=deletionAtFirst(head);
    // head=deletionAtIndex(head,2);
    // head=deletionAtEnd(head);
    // head=deletionValue(head,4);
    // head=deletionTillIndex(head,1);
    linkedListTraversal(head);
    return 0;
}