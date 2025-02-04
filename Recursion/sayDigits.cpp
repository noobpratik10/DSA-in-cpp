/*
-->Input:-412 --->Function ---> Output:-Four One Two
    Write a function that satisfies the following conditon.
*/

#include <bits/stdc++.h>
using namespace std;
void sayDigits(int n, string arr[])
{
    // Base Condition
    if (n == 0)
    {
        return;
    }
    else
    {

        /*
          Head recurion-->will display number inreverse
              // Processing
              int digit = n % 10;
              n = n / 10;
              cout << arr[digit] << " ";

              // Recursive call
              sayDigits(n, arr);
        */
        // Tail recursion
        int digit = n % 10;
        n = n / 10;

        //  Recursive call
        sayDigits(n, arr);

        // Processing
        cout << arr[digit] << " ";
    }
}

int main()
{
    string arr[10] = {"Zero", "One", "Two", "Three",
                      "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    cout << "Enter any number here: " << endl;
    int n;
    cin >> n;
    cout << "Answer: " << endl;
    sayDigits(n, arr);

    return 0;
}