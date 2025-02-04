#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*implementation is in the form of single end queue(FIFO)*/
    queue<int> q;

    q.push(5);
    q.push(4);
    q.push(1);
    q.push(7);
    q.push(8);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.size();
    return 0;
}