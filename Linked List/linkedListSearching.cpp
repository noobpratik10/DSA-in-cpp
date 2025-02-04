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

class Node *linearSearch(class Node *head, int value)
{
    class Node *ptr = head;
    int index = 1;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            cout << "Element found at " << index << "th position." << endl;
            return head;
        }
        else if (ptr->data != value)
        {
            ptr = ptr->next;
            index++;
        }
    }

    cout << "Element not found in the list." << endl;
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
    head = linearSearch(head, 76);
    head = linearSearch(head, 4);
    linkedListTraversal(head);

    return 0;
}