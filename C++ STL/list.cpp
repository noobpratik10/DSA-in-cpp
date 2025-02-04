#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*implementation is in the form of doubly linked list*/

    list<int> l;
    l.push_back(4);
    l.push_front(4);

    for (auto i : l)
    {
        cout << i << endl;
    }

    l.erase(l.begin());

    l.pop_back();
    l.pop_front();
    l.size();

    list<int> n(l);       // copies previous list in new list
    list<int> l1(5, 100); //(size,initializedValue)
    return 0;
}