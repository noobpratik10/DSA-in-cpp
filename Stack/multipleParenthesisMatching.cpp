#include <iostream>
using namespace std;

// Program to determine whether the equation is balanced or unbalanced based on multiple parenthesis checking using stackArray.

// creating class stack as a checker for paranthesis
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

    char pop(class stack *ptr)
    {
        if (top != -1)
        {
            char poppedItem;
            poppedItem = ptr->arr[top];
            ptr->top--;
            return poppedItem;
        }
        else
        {
            cout << "Stack is empty(Stack underflow). Cannot execute pop()" << endl;
            char o;
            return o;
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

// function to match popped element and expression[i]
int match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void parenthesisMatchChecker(char expression[], int n)
{
    // creating stack checker dynamically in heap
    class stack *checker = new stack(n);

    // parenthesis checking usinf for loop
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))
        {
            checker->push(checker, expression[i]);
        }
        else if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
        {
            char a = checker->pop(checker);
            if ((a == 'o') || (match(a, expression[i]) == 0))
            {
                cout << "The parenthesis is not matching. Equation is unbalanced." << endl;
                break;
            }
        }
    }

    // final checking
    if ((i == n) && (checker->isEmpty(checker) == -1))
    {
        cout << "The parenthesis is matching. Equation is balanced." << endl;
    }
    else if ((i == n) && (checker->isEmpty(checker) != -1))
    {
        cout << "The parenthesis is not matching. Equation is unbalanced." << endl;
    }
}

int main()
{
    // getting size of expression from user
    cout << "Enter size of the expression here:" << endl;
    int n;
    cin >> n;

    // getting expression from user input
    cout << "Enter the expression here:" << endl;
    char expression[n];
    for (int i = 0; i < n; i++)
    {
        cin >> expression[i];
    }

    // displaying entered expression
    cout << "Entered expression is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << expression[i];
    }
    cout << endl;

    // calling parenthesismatchchecker function
    parenthesisMatchChecker(expression, n);

    return 0;
}