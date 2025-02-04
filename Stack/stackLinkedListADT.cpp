#include <iostream>
using namespace std;

// implementing stack using linked list
class node
{
public:
    int data;
    // int position;-->ispe baadme kaam karna tu stack ki upper limit set karne ke liye
    class node *next;
};

void stackDisplay(class node *top)
{
    class node *ptr = top;
    cout << "Elements in the stack are:" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int isEmpty(class node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty.(Stack underflow)" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    class node *n = (class node *)malloc(sizeof(class node));
    if (n == NULL)
    {
        cout << "Stack is full.(Stack overflow)" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

class node *push(class node *top, int value)
{
    if (isFull() == 1)
    {
        cout << "Cannot perform push operation as stack is full." << endl;
        return top;
    }
    else
    {
        node *ptr = (class node *)malloc(sizeof(class node));
        ptr->data = value;
        ptr->next = top;
        return ptr;
    }
}

class node *pop(class node *top)
{
    if (isEmpty(top) == 1)
    {
        cout << "Cannot execute pop() as stack is empty." << endl;
        return 0;
    }
    else
    {
        node *ptr = (class node *)malloc(sizeof(class node));
        ptr = top->next;
        cout << "Popped element is: " << top->data << endl;
        free(top);
        return ptr;
    }
}

void peek(class node *top, int position)
{
    class node *ptr = top;
    for (int i = 1; (i < position && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
    cout << "Element at " << position << "th position is :" << ptr->data << endl;
    }
    else{
        cout<<"Position out of range."<<endl;
    }
}

int stackTop(class node *top)
{
    return top->data;
}

int stackBottom(class node *top)
{
    class node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{

    node *top, *second, *third, *bottom;

    top = (class node *)malloc(sizeof(class node));
    second = (class node *)malloc(sizeof(class node));
    third = (class node *)malloc(sizeof(class node));
    bottom = (class node *)malloc(sizeof(class node));
    // or we can use new operator
    // top = new node;
    // second = new node;
    // third = new node;
    // bottom = new node;

    top->data = 7;
    top->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = bottom;
    bottom->data = 8;
    bottom->next = NULL;
    cout << "Stack has been created successfully." << endl;

    stackDisplay(top);

    top = push(top, 67);
    top = push(top, 67);
    top = push(top, 67);
    stackDisplay(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    stackDisplay(top);

    isEmpty(top);

    peek(top, 3);

    cout << "Element at top of the stack is :" << stackTop(top) << endl;
    cout << "Last element of the stack is :" << stackBottom(top) << endl;

    return 0;
}