#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define m 1000000007

vector<int> fact(1e6 + 1, 0);

void getFact()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}

ll binpow(ll a, ll b)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Fermat's Theorem
//  if modulo is prime then
//  b^(m-2)=1/b
//  this can be used to find a^b

ll modInverse(ll n)
{
    return binpow(n, m - 2);
}

ll nCr(ll n, ll r)
{
    ll factN = fact[n] % m;
    ll factD = (fact[n - r] * fact[r]) % m;
    return (factN * modInverse(factD)) % m;
}

int main()
{
    getFact();
    cout << nCr(12, 4);
    return 0;
}