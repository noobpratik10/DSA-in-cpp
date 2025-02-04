/*Its also a static array*/
#include <bits/stdc++.h>
#include <array>
using namespace std;
int main()
{

    array<int, 4> a = {1, 3, 2, 4};
    int size = a.size();

    for (auto I : a)
    {
        cout << a[I] << endl;
    }

    cout << "Element at second index" << a.at(2) << endl;

    cout << "Array is empty or not" << a.empty() << endl;

    cout << "First eleement" << a.front() << endl;
    cout << "Last element" << a.back() << endl;

    return 0;
}