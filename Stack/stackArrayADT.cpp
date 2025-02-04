#include<iostream>
using namespace std;

class stack{
    public:
    int size;
    int top;
    int *arr;
    
    // using a parameterized constructor to create a stack
    stack(int size){
        // use of ->'this'<- keyword 

        // as 'this' is a reference variable and not a pointer.
        // local variable is same as a member's name 
        // The 'this' pointer is used to retrieve the object's x
        // hidden by the local variable 'x'
        
        this->size=size;
        this->top=-1;
        this->arr=(int *)malloc(this->size*(sizeof(int)));
        cout<<"Stack has been created successfully."<<endl;
    }

    // Defining basic operation functions for stack
    void push(class stack *ptr,int value){
        if(top<(size-1)){          
            ptr->arr[ptr->top+1]=value;
            ptr->top++;
        }
        else{
            cout<<"Stack is full(Stack overflow). Cannot execute push()"<<endl;
        }
    }

    int pop(class stack *ptr){
        if(top!=-1){
            int poppedItem;
            poppedItem=ptr->arr[top];
            ptr->top--;
            return poppedItem;
        }
        else{
            cout<<"Stack is empty(Stack underflow). Cannot execute pop()"<<endl;
            return 0;
        }
    }

    void display(class stack *ptr){
        cout<<"Elements in the stack are:"<<endl;
        for(int i=1;i<=ptr->top+1;i++){
            cout<<ptr->arr[ptr->top-i+1]<<" ";
        }
        cout<<endl;
    }

    int isEmpty(class stack *ptr){
        if(ptr->top==-1){
            cout<<"Stack is empty."<<endl;
            return top;
        }
        else{
            cout<<"Stack is not empty."<<endl;
            return top;
        }
    }

    int isFull(class stack *ptr){
        if(ptr->top==ptr->size-1){
            cout<<"Stack is full."<<endl;
            return top;
        }
        else{
            cout<<"Stack is not full."<<endl;
            return top;
        }
    }

    int peek(class stack *ptr,int position){
        int arrayInd=top-position+1;
        return ptr->arr[arrayInd];
    }

    int stackBottom(class stack *s){
        return s->arr[0];
    }

    int stackTop(class stack *s){
        return s->arr[top];
    }
};


int main(){
    
    // Taking size of the stack from user input:-
    cout<<"Enter the size of the stack to be created:"<<endl;
    int n;
    cin>>n;
    
    // stack array is dynamically created using a parameterized constructor:-
    class stack *s=new stack(n);/* Here, ->'new'<- keyword is used intead of malloc for dynamic memory allocation */
    
    // Following steps can be used in C language:-
        // class stack *s=new stack;
        // s->size=100;
        // s->top=-1;
        /* Here 'malloc' keyword is used for dynamic memory allocation */
        // s->arr=(int *)malloc(s->size*(sizeof(int)));

    // calling functions
    s->top=s->isEmpty(s);
    s->top=s->isFull(s);
    
    s->push(s,56);
    s->push(s,23);
    s->push(s,45);
    s->push(s,78);
    s->push(s,13);
    s->push(s,90);
    s->display(s);

    int a,b,c;
    a=s->pop(s);
    b=s->pop(s);
    c=s->pop(s);
    cout<<"Popped items are: "<<a<<" "<<b<<" "<<c<<endl;
    
    s->display(s);

    for(int i=1;i<=s->top+1;i++){
        
        cout<<"Elements at "<<i<<"th position is: "<<s->peek(s,i)<<endl;
    }

    cout<<"Element at top of the stack is:"<<s->stackTop(s)<<endl;
    cout<<"Element at bottom of the stack is:"<<s->stackBottom(s)<<endl;
    
    return 0;
}