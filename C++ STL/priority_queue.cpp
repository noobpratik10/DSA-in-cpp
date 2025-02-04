#include <bits/stdc++.h>
using namespace std;

class Compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        //ascending
        if(a.first==b.first){
            return a.second<a.second;
        }
        return a.first<a.first;

        //descending
        if(a.first==b.first){
            return a.second>a.second;
        }
        return a.first>a.first;

        //ascending --second parameter
        return a.second<b.second

        //descending second parameter
        return a.second>b.second;

    }
};

int main()
{
    /*Priority queue in implementation in the form of queue,
    but jab element bahar nikalenge to always max/min niklegene(sorted ordder)*/

    // max - heap
    priority_queue<int> maxi;

    // mini - heap
    priority_queue<int, vector<int>, greater<int>> mini;


    // custom heap
    Compare comp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;   //data type container comparator
    
    maxi.push(4);
    maxi.push(1);
    maxi.push(10);
    maxi.push(6);
    maxi.push(8);

    cout << "size->" << maxi.size() << endl;
    int n = maxi.size();

    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << endl;
        maxi.pop();
    }

    maxi.empty();

    mini.push(4);
    mini.push(1);
    mini.push(10);
    mini.push(6);
    maxi.push(8);

    cout << "size->" << mini.size() << endl;
    int n = mini.size();

    for (int i = 0; i < n; i++)
    {
        cout << mini.top() << endl;
        mini.pop();
    }

    mini.empty();
    return 0;
}