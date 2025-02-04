// Here's a short c++ implementation of the above solution:

#include <iostream>
using namespace std;

const int N = 1000;
int T[N] = {}, q, z;

int main()
{
    for (int g = 1; g < N; g++)
        for (int x = 1; g * x + g < N; x++)
            if (((g * x + g) ^ (g * x)) == g)
                T[g * x + g]++;
    for (int i = 2; i < N; i++)
        T[i] += T[i - 1];

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> z;
        cout << "Case " << i << ": " << T[z] << endl;
    }
}