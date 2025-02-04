#include <iostream>
using namespace std;

class circularQueue
{
private:
    int f;
    int r;
    int size;
    int *arr;

public:
    circularQueue(int n)
    {
        this->size = n;
        this->arr = (int *)malloc(size * (sizeof(int)));
        this->f = 0;
        this->r = 0;
        cout << "Circular Queue has been created successfully." << endl;
    }

    int isEmpty(class circularQueue *cq)
    {
        if (cq->r == cq->f)
        {
            cout << "Queue is Empty." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull(class circularQueue *cq)
    {
        if ((cq->r + 1) % cq->size == cq->f)
        {
            cout << "Queue is Full." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(class circularQueue *cq, int value)
    {
        if (isFull(cq) == 1)
        {
            cout << "Cannot execute enqueue operation." << endl;
        }
        else
        {
            cq->r = (r + 1) % size;
            cq->arr[cq->r] = value;
            cout << "Enqueued element:" << cq->arr[cq->r] << endl;
        }
    }

    int dequeue(class circularQueue *cq)
    {
        if (isEmpty(cq) == 1)
        {
            cout << "Cannot execute dequeue operation." << endl;
            return -1;
        }
        else
        {

            int a = cq->arr[cq->f + 1];
            cq->arr[cq->f + 1] = 0;
            cq->f = (f + 1) % size;
            cout << "Dequeued element:" << a << endl;
            return a;
        }
    }

    int firstVal(circularQueue *cq)
    {
        if (isEmpty(cq) == 1)
        {
            cout << "Cannot execute firstVal operation." << endl;
            return -1;
        }
        else
        {

            return cq->arr[cq->f + 1];
        }
    }

    int lastVal(circularQueue *cq)
    {
        if (isEmpty(cq) == 1)
        {
            cout << "Cannot execute lastVal operation." << endl;
            return -1;
        }
        else
        {

            return cq->arr[cq->r];
        }
    }

    int peek(circularQueue *cq, int index)
    {
        if (isEmpty(cq) == 1)
        {
            cout << "Cannot execute peek operation." << endl;
            return -1;
        }
        else
        {
            return cq->arr[index + 1];
        }
    }

    void display(circularQueue *cq)
    {
        cout << "Elements in the queue are:" << endl;

        for (int i = cq->f; i < cq->r; i = (i + 1) % cq->size)
        {
            cout << peek(cq, i) << " ";
        }
        cout << endl;
    }
};

int main()
{

    int n = 10;
    // cin>>n;
    class circularQueue *cq = new circularQueue(n);

    cq->enqueue(cq, 5);
    cq->enqueue(cq, 2);
    cq->enqueue(cq, 69);
    cq->enqueue(cq, 45);
    cq->display(cq);

    cq->dequeue(cq);
    cq->dequeue(cq);
    // cout << "Dequeuing element: " << cq->dequeue(cq) << endl;
    cq->display(cq);

    cout << "First element of queue is:" << cq->firstVal(cq) << endl;
    cout << "Last element of queue is:" << cq->lastVal(cq) << endl;

    cq->enqueue(cq, 78);
    cq->enqueue(cq, 9);
    cq->enqueue(cq, 36);
    cq->display(cq);
    return 0;
}