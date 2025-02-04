#include <bits/stdc++.h>
#include <deque>
/*its imllementation is double ended queue
    insertion and deletion can hapen at both the ends
*/
using namespace std;
int main()
{

    deque<int> d;

    d.push_back(1);
    d.push_front(4);

    for (auto i : d)
    {
        cout << i << endl;
    }

    d.pop_front();
    d.pop_back();

    cout << d.at(0);
    cout << d.empty() << endl;
    cout << d.front() << endl;
    cout << d.back() << endl;
    cout << d.size();
    d.erase(d.begin(), d.begin() + 1);
    return 0;
}