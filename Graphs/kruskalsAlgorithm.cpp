#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Kruskal's Algorithm:- Algorithm to get minimum spaning trree(MST) of the graph.
                      It doesn't requires adjacency list of the graph.

Spanning Tree:- Graph with n nodes converted into tree with n nodes and n-1 edges

Min. Spanning Tree(MST):-Spanning tree with minimum cost of weight
*/

// custom compare function
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

// set initializing function
void makeSet(vector<int> &parent, vector<int> &rank)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// fiding parent function
int findParent(int node, vector<int> &parent)
{
    // base case
    if (parent[node] == node)
    { // node ka parent khud h to return karo
        return node;
    }
    // node ke parent ke liye call karo & last me parent update karo
    return parent[node] = findParent(parent[node], parent); // path compression -->iske bina bhi kam chalega
}

// unionSet aka merge function used to merge small tree into bigger tree
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // get parent of both nodes
    int p1 = findParent(u, parent);
    int p2 = findParent(v, parent);

    // attach according to rank of the parents
    if (rank[p1] < rank[p2])
    {
        parent[p1] = p2;
    }
    else if (rank[p1] > rank[p2])
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p1] = p2;
        rank[p2]++;
    }
}

int main()
{
    // get no. of vertices and edges
    int v, e;
    cin >> v >> e;

    // create vector for edges
    vector<vector<int>> edges; // w u v
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp;
        temp.push_back(w);
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }

    // sort edges vector with custom comparator
    sort(edges.begin(), edges.end(), cmp);

    // make necessary data structures & functions
    vector<int> parent(v);
    vector<int> rank(v);
    makeSet(parent, rank);

    // traverse each edge & if diff. merge them
    int minWeight = 0;
    for (int i = 0; i < e; i++)
    {
        // get parents
        int u = edges[i][1];
        int v = edges[i][2];
        int p1 = findParent(u, parent);
        int p2 = findParent(v, parent);
        int weight = edges[i][0];

        // if diff merge
        if (p1 != p2)
        {
            minWeight += weight;
            unionSet(u, v, parent, rank);
        }
    }

    // printing the result
    cout << "MST: " << endl;
    cout << "child --> parent" << endl;
    for (int i = 0; i < parent.size(); i++)
    {
        cout << i << " --> " << parent[i] << endl;
    }

    cout << "Cost of the MST is: " << minWeight << endl;

    return 0;
}