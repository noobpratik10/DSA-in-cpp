#include <iostream>
using namespace std;

// Floyd's cycle detection algorithm:-
// Pseudocode:
// 1)Initialize two-pointers and start traversing the linked list.
// 2)Move the slow pointer by one position.
// 3)Move the fast pointer by two positions.
// 4)If both pointers meet at some point then a loop exists and if the fast pointer meets the end position then no loop exists.

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

bool cyclePresent(class Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    else
    {
        class Node *slow = head;
        class Node *fast = head->next;

        while (fast != NULL && fast->next != NULL && slow != NULL)
        {
            if (slow == fast)
            {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
}

class Node *cycleHead(class Node *head)
{

    class Node *slow = head;
    class Node *fast = head;

    while (fast != NULL && fast->next != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
int main()
{

    Node *head, *second, *third, *fourth, *fifth, *sixth;
    head = (class Node *)malloc(sizeof(class Node));
    second = (class Node *)malloc(sizeof(class Node));
    third = (class Node *)malloc(sizeof(class Node));
    fourth = (class Node *)malloc(sizeof(class Node));
    fifth = (class Node *)malloc(sizeof(class Node));
    sixth = (class Node *)malloc(sizeof(class Node));

    head->data = 7;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 8;
    fourth->next = fifth;

    fifth->data = 8;
    fifth->next = sixth;

    sixth->data = 8;
    sixth->next = fourth;

    // linkedListTraversal(head);

    if (cyclePresent(head))
    {
        cout << "Cycle is Present." << endl;
        class Node *loopHead = cycleHead(head);
        cout << "Data at cycleHead is:" << loopHead->data << endl;
    }
    else
    {
        cout << "Cycle is Absent in the loop." << endl;
    }
    return 0;
}