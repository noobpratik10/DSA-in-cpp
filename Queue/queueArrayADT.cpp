#include <iostream>
using namespace std;

class Queue
{

    int frontInd;
    int backInd;
    int size;
    int *arr;

public:
    Queue(int n)
    {
        this->size = n;
        this->arr = (int *)malloc(size * (sizeof(int)));
        this->frontInd = -1;
        this->backInd = -1;
        cout << "Queue has been created successfully." << endl;
    }

    int isEmpty(class Queue *q)
    {
        if (q->backInd == q->frontInd)
        {
            cout << "Queue is empty." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull(class Queue *q)
    {
        if (q->backInd == q->size - 1)
        {
            cout << "Queue is full." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(class Queue *q, int value)
    {
        if (isFull(q) == 1)
        {
            cout << "Cannot execute insertion operation." << endl;
        }
        else
        {
            q->backInd++;
            q->arr[q->backInd] = value;
            cout << "Enqueued element:" << q->arr[q->backInd] << endl;
        }
    }

    int dequeue(class Queue *q)
    {
        int a = -1;
        if (isEmpty(q) == 1)
        {
            cout << "Cannot execute deletion operation." << endl;
            return a;
        }
        else
        {
            a = q->arr[q->frontInd + 1];
            q->arr[q->frontInd + 1] = 0;
            q->frontInd++;
            cout << "Dequeued element:" << a << endl;
            return a;
        }
    }

    int firstVal(class Queue *q)
    {
        if (isEmpty(q))
        {
            cout << "Cannot execute firstVal operation." << endl;
            return 0;
        }
        else
        {
            return q->arr[q->frontInd + 1];
        }
    }

    int lastVal(class Queue *q)
    {
        if (isEmpty(q))
        {
            cout << "Cannot execute lastVal operation." << endl;
            return 0;
        }
        else
        {
            return q->arr[q->backInd];
        }
    }

    int peek(class Queue *q, int index)
    {
        if (isEmpty(q))
        {
            cout << "Cannot execute peek operation." << endl;
            return 0;
        }
        else
        {
            return q->arr[index];
        }
    }

    void display(class Queue *q)
    {
        cout << "Queue:" << endl;
        for (int i = q->frontInd + 1; i <= q->backInd; i++)
        {
            cout << q->peek(q, i) << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 50;
    // cin>>n;
    class Queue *q = new Queue(n);

    q->enqueue(q, 43);
    q->enqueue(q, 34);
    q->enqueue(q, 87);
    q->enqueue(q, 94);
    q->enqueue(q, 51);
    q->display(q);

    q->dequeue(q);
    q->dequeue(q);
    q->dequeue(q);
    q->display(q);

    q->enqueue(q, 56);
    q->enqueue(q, 90);
    q->enqueue(q, 23);
    q->display(q);

    cout << "First element of queue is:" << q->firstVal(q) << endl;
    cout << "Last element of queue is:" << q->lastVal(q) << endl;

    return 0;
}