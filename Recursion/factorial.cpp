#include <iostream>
using namespace std;

int factorial(int n)
{

    // Base condition
    if (n == 0)
    {
        return 1;
    }
    // Recursive call
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    cout << "Enter the no. whose factorial you want to find out:" << endl;
    int n;
    cin >> n;

    cout << "n ! = " << factorial(n) << endl;

    return 0;
}