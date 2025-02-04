#include <iostream>
using namespace std;

class DEQueue
{

    int frontInd;
    int backInd;
    int size;
    int *arr;

public:
    DEQueue(int n)
    {
        this->size = n;
        this->arr = (int *)malloc(size * (sizeof(int)));
        this->frontInd = -1;
        this->backInd = -1;
        cout << "DEQueue has been created successfully." << endl;
    }

    int isEmpty(class DEQueue *q)
    {
        if (q->backInd == q->frontInd)
        {
            cout << "DEQueue is empty." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull(class DEQueue *q)
    {
        if (q->backInd == q->size - 1 && q->frontInd == -1)
        {
            cout << "DEQueue is full." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueueR(class DEQueue *q, int value)
    {
        if (q->backInd == q->size - 1)
        {
            cout << "Cannot execute enqueueR operation." << endl;
        }
        else
        {
            q->backInd++;
            q->arr[q->backInd] = value;
            cout << "Enqueued element at rear :" << q->arr[q->backInd] << endl;
        }
    }

    void enqueueF(class DEQueue *q, int value)
    {
        if (q->frontInd == -1)
        {
            cout << "Cannot execute enqueueF operation." << endl;
        }
        else
        {
            q->arr[q->frontInd] = value;
            q->frontInd--;
            cout << "Enqueued element at front :" << q->arr[q->frontInd + 1] << endl;
        }
    }

    int dequeueF(class DEQueue *q)
    {
        int a = -1;
        if (isEmpty(q) == 1)
        {
            cout << "Cannot execute dequeueF operation." << endl;
            return a;
        }
        else
        {
            a = q->arr[q->frontInd + 1];
            q->arr[q->frontInd + 1] = 0;
            q->frontInd++;
            cout << "Dequeued element at front :" << a << endl;
            return a;
        }
    }

    int dequeueR(class DEQueue *q)
    {
        int a = -1;
        if (isEmpty(q) == 1)
        {
            cout << "Cannot execute dequeueR operation." << endl;
            return a;
        }
        else
        {
            a = q->arr[q->backInd];
            q->arr[q->backInd] = 0;
            q->backInd--;
            cout << "Dequeued element at rear :" << a << endl;
            return a;
        }
    }

    int firstVal(class DEQueue *q)
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

    int lastVal(class DEQueue *q)
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

    int peek(class DEQueue *q, int index)
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

    void display(class DEQueue *q)
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
    class DEQueue *q = new DEQueue(n);

    q->enqueueR(q, 43);
    q->enqueueR(q, 34);
    q->enqueueR(q, 87);
    q->enqueueR(q, 94);
    q->enqueueR(q, 51);
    q->display(q);

    q->dequeueF(q);
    q->dequeueF(q);
    q->dequeueF(q);
    // q->dequeueF(q);
    q->display(q);

    // q->enqueueR(q, 56);
    q->enqueueF(q, 90);
    q->enqueueF(q, 23);
    q->enqueueR(q,72);
    q->enqueueR(q,69);
    q->display(q);

    cout << "First element of queue is:" << q->firstVal(q) << endl;
    cout << "Last element of queue is:" << q->lastVal(q) << endl;

    return 0;
}