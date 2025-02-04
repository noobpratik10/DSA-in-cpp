#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
    class Node *prev;
};

class Node *binaryListTraversal(class Node *head, class Node *tail)
{
    // Method 1:-
    class Node *ptr1 = head;
    cout << "Binary list traversal by method 1:-" << endl;
    while (ptr1 != NULL)
    {
        cout << ptr1->data << " ";
        ptr1 = ptr1->next;
    }
    cout << endl;
    class Node *ptr2 = tail;
    cout << "Binary list traversal by method 2:-" << endl;
    while (ptr2 != NULL)
    {
        cout << ptr2->data << " ";
        ptr2 = ptr2->prev;
    }
    cout << endl;
    return head, tail;
}

int main()
{

    // Node declaration
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    Node *tail;

    // Dynamic Memory Allocation in Heap
    head = (class Node *)malloc(sizeof(class Node));
    second = (class Node *)malloc(sizeof(class Node));
    third = (class Node *)malloc(sizeof(class Node));
    fourth = (class Node *)malloc(sizeof(class Node));
    tail = (class Node *)malloc(sizeof(class Node));

    // Link formation
    head->next = second;
    head->prev = NULL;
    second->next = third;
    second->prev = head;
    third->next = fourth;
    third->prev = second;
    fourth->next = tail;
    fourth->prev = third;
    tail->next = NULL;
    tail->prev = fourth;

    // Data filling
    head->data = 1;
    second->data = 3;
    third->data = 5;
    fourth->data = 7;
    tail->data = 9;

    // binary list traversal:-
    head, tail = binaryListTraversal(head, tail);

    return 0;
}