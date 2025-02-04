#include <bits/stdc++.h>
using namespace std;

/*
    Catalan numbers:-

        C(0)=C(1)=1
        C(n)=sum(0,n-1): {Ci * Cn-i}

*/

int catalan(int n)
{
    // Base condition:
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

int main()
{

    int n;
    cin >> n;

    cout << "Nth term of catalan sequence is :" << catalan(n) << endl;
    return 0;
}