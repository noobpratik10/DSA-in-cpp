#include <iostream>
using namespace std;

int power(int a, int b)
{ // method 1:-
    // // Base case
    // if (b == 0)
    // {
    //     return 1;
    // }

    // if (b == 1)
    // {
    //     return a;
    // }

    // // Recursive call
    // return a * power(a, b - 1);

    // Optimized method:-
    //  base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    // Recursive call
    int ans = power(a, b / 2);

    // Processing
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    cout << "Enter the base:" << endl;
    int a;
    cin >> a;
    cout << "Enter the power:" << endl;
    int b;
    cin >> b;

    cout << power(a, b) << endl;
    return 0;
}