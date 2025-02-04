// Functions to find gcd of two given numbers
#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(log(min(a,b)))
// Space Complexity:- O(1)

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a < b)
            b = b % a;
        else
            a = a % b;
    }
    if (a == 0)
        return b;
    else
        return a;
}

// STL Fnction
//  __gcd(int a,int b)

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}