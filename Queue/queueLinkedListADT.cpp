#include<iostream>
using namespace std;

class Queue *f=NULL;
class Queue *r=NULL;


class Queue{
    public:
    int data;
    class Queue *next;

    public:

    int isFull(){
        class Queue *ptr= (class Queue *)malloc(sizeof(class Queue));
        if(ptr==NULL){
            cout<<"Queue is Full."<<endl;
            return 1;
        }
        else{
            return 0;
        }

    }

    int isEmpty(){
        if(f==NULL){
            cout<<"Queue is Empty."<<endl;
            return 1;
        }
        else{
            return 0;
        }

    }

    void enqueue(int value){
        if(isFull()==1){
            cout<<"Cannot execute enqueue operation."<<endl;
        }
        else{
            class Queue *ptr= (class Queue *)malloc(sizeof(class Queue));
            ptr->data=value;
            ptr->next=NULL;
            if(f==NULL){
                f=r=ptr;
            }
            else{
                r->next=ptr;
                r=ptr;
            }
            cout<<"Enqued element"<<ptr->data<<endl;

        }
    }

    int dequeue(){
        int value=-1;
        if(isEmpty()==1){
            cout<<"Cannot execute dequeue operation."<<endl;
            return value;
        }
        else{
            class Queue *ptr=f;
            value=ptr->data;
            cout<<"Dequed element"<<ptr->data<<endl;
            f=f->next;
            free(ptr);
            return value;
        }
    }

    int firstVal(){
        if(isEmpty()==1){
            cout<<"Cannot execute firstVal operation."<<endl;
            return 0;
        }
        else{
            return f->data;
        }
    }

    int lastVal(){
        if(isFull()==1){
            cout<<"Cannot execute lastVal operation."<<endl;
            return 0;
        }
        else{
            return r->data;
        }
    }

    int peek( int position){
        if(isEmpty()==1){
            cout<<"Cannot execute firstVal operation."<<endl;
            return 0;
        }
        else{
            class Queue *ptr=f;
            int i=1;
            while(i!=position){
                ptr=ptr->next;
                i++;
            }
            return ptr->data;
        }
    }

    void queueTraversal()
    {
    class Queue *ptr = f;
    cout << "Elements of the queue are:" << endl;
    while (ptr != NULL)
    {
        cout << "Element:" << ptr->data << endl;
        ptr = ptr->next;
    }
    }
};


int main(){
    class Queue *q;
    q->enqueue(34);
    q->enqueue(24);
    q->enqueue(14);
    q->enqueue(10);
    q->enqueue(89);
    q->enqueue(69);
    q->queueTraversal();

    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->queueTraversal();

return 0;
}