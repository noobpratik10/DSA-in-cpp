#include <iostream>

/*
    -->A person con climb one or at most two steps at a time.
    You are given no. of steps to climb as input.
    Find out maximum no. of posiible ways to reach at the top.


                     ____
                  __|
               __|
            __|
         __|
    ____|

*/

int climbSteps(int n)
{
    // Base condition
    if (n == 0)
    {
        return 1; //--->Only one way.Hop on the ground
    }
    else if (n < 0)
    {
        return 0;
    }
    // Recursive call
    else
    {
        return climbSteps(n - 1) + climbSteps(n - 2);
    }
}

using namespace std;
int main()
{
    cout << "Enter the no. of steps to reach at the top: " << endl;
    int n;
    cin >> n;
    cout << "No. of ways to reach at the top are: " << climbSteps(n);
    return 0;
}