// Simple sieve
/*
--> This is an algorithm for efficient calculation of all the prime numbers from 0 to n.
-->Its Time complexity is better than T(n)=O(n^2).

-->Time complexity :T(n)=O(nlog(log(n)))
-->Space complexity :S(n)=O(n)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int> &prime)
{
    vector<bool> nums(n + 1, true);
    nums[0] = false;
    nums[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (nums[i])
        {
            prime.push_back(i);
            for (int j = 2; i <= n; j = j + i)
            {
                nums[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> prime;
    cout << "Prime numbers from 0 to" << n << " are:" << endl;
    sieve(n, prime);
    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << " ";
    }
    return 0;
}