#include <iostream>
#include <cstring>
using namespace std;
// Program to convert mathematical epression from infix to postfix form

class stack
{
public:
    int size;
    int top;
    char *arr;

    // using a parameterized constructor to create a stack
    stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = (char *)malloc(this->size * (sizeof(char)));
        cout << "Stack has been created successfully." << endl;
    }

    void push(class stack *ptr, char value)
    {
        if (top < (size - 1))
        {
            ptr->arr[ptr->top + 1] = value;
            ptr->top++;
        }
        else
        {
            cout << "Stack is full(Stack overflow). Cannot execute push()" << endl;
        }
    }

    int pop(class stack *ptr)
    {
        if (top != -1)
        {
            int poppedItem = ptr->arr[top];
            ptr->top--;
            return poppedItem;
        }
        else
        {
            cout << "Stack is empty(Stack underflow). Cannot execute pop()" << endl;
            return 0;
        }
    }

    int isEmpty(class stack *ptr)
    {
        if (ptr->top == -1)
        {
            cout << "Stack is empty." << endl;
            return top;
        }
        else
        {
            cout << "Stack is not empty." << endl;
            return top;
        }
    }

    int isFull(class stack *ptr)
    {
        if (ptr->top == ptr->size - 1)
        {
            cout << "Stack is full." << endl;
            return top;
        }
        else
        {
            cout << "Stack is not full." << endl;
            return top;
        }
    }
};

int precedenceChecker(char a)
{
    if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *postFixConverter(char *expression)
{

    class stack *checker = new stack(50);
    char *postfix = new char[strlen(expression) + 1];

    int i = 0; // Infix tracker
    int j = 0; // Postfix tracker
    while (expression[i] != '\0')
    {

        if (isOperator(expression[i]) == 0)
        {
            postfix[j] = expression[i];
            i++;
            j++;
        }
        else
        {
            if (precedenceChecker(expression[i]) > precedenceChecker(checker->arr[checker->top]))
            {
                checker->push(checker, expression[i]);
                i++;
            }
            else
            {
                postfix[j] = checker->pop(checker);
                j++;
            }
        }
    }

    while (checker->isEmpty(checker) != -1)
    {
        postfix[j] = checker->pop(checker);
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{

    // giving the infix expression
    char *expression = "a+b*c";

    // calling postFixconverter function
    cout << "Postfix of the above expression is " << postFixConverter(expression);
    // delete[] postfix;

    return 0;
}