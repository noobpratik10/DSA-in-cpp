#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*stored in the form of key value,its sorted in ap & unsorted in unordered map,implementation using balanced tree
    for unordered map implemmntation using hash tables*/

    map<int, string> m;

    m[2] = "patik";
    m[3] = "patil";
    m[1] = "jitendra";

    m.insert({5, "iloveeyou"});

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "is 34 prent ?" << m.count(34) << endl;
    auto it = m.find(2);
    m.erase(5);

    return 0;
}