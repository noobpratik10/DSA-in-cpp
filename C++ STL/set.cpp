#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*set-->only stores unique elements and gives element in sorted order
    time compleities are logn and 1*/

    set<int> s;

    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);

    int top=*(s.begin());

    for (auto i : s)
    {
        cout << i << endl;
    }

    s.erase(s.begin());

    cout << "Is 5 present in the set" << s.count(5) << endl;

    set<int>::iterator itr = s.find(5);

    return 0;
}