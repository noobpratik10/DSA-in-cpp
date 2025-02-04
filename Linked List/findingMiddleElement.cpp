#include <iostream>
using namespace std;

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

void middleElementSearch(class Node *head)
{
    class Node *ptr = head;
    int size = 0;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    cout << "Size of the linked list is:" << size << endl;
    int middle = int(size / 2) + 1;

    class Node *ptr2 = head;
    for (int i = 0; i < middle - 1; i++)
    {
        ptr2 = ptr2->next;
    }
    cout << "Position of middle element is:" << middle << endl;
    cout << "Data at middle element is:" << ptr2->data << endl;
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
    middleElementSearch(head);
    return 0;
}