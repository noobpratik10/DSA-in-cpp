#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*Implementation is in the form of stack with top pointer*/

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    s.size();
    s.empty();
    return 0;
}