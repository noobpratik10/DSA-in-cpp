#include <bits/stdc++.h>
using namespace std;
/*
Kosaraju's Algorithm:-
    Its used to find no. of stronly connected components(s.c.c's)
    in the graph.
    It takes advantage of the fact that no. of s.c.c count for a graph
    and its transpose remains same.

Strongly Connected Components:-
    Component of the graph in which we can travel from each node
    to each node.
    Its also called as scc.

Transpose of Graph:-
    Same graph with each edge reveresed.
*/

// creating directed graph class
class graph
{
public:
    int nodes;
    unordered_map<int, list<int>> adjList;

    graph(int n)
    {
        nodes = n;
        for (int i = 0; i < nodes; i++)
        {
            list<int> l;
            pair<int, list<int>> p = make_pair(i, l);
            adjList.insert(p);
        }
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        cout << "Edge created successfully." << endl;
    }

    void printAdjList()
    {
        cout << "Adjacent List of the graph is :" << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << i << "-->";
            for (auto j : adjList[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // topo sort dfs function
    void topoSortDFS(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (auto nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                topoSortDFS(nbr, visited, st);
            }
        }

        // top logic
        st.push(node);
    }

    // transponse dfs function
    void transposeDFS(int node, unordered_map<int, bool> &visited,
                      unordered_map<int, list<int>> &transposeAdj)
    {
        visited[node] = true;

        for (auto nbr : transposeAdj[node])
        {
            if (!visited[nbr])
            {
                transposeDFS(nbr, visited, transposeAdj);
            }
        }
    }
};

int main()
{
    // creating a directed graph
    graph *g = new graph(5);
    g->addEdge(0, 4);
    g->addEdge(4, 1);
    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 2);
    g->printAdjList();

    // Step1) getting topological sort of the graph
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < g->nodes; i++)
    {
        if (!visited[i])
        {
            g->topoSortDFS(i, visited, st);
        }
    }

    // Step2) making transpose adjList of graph & unmarking visited
    unordered_map<int, list<int>> transposeAdj;
    for (int i = 0; i < g->nodes; i++)
    {
        visited[i] = false;
        for (auto nbr : g->adjList[i])
        {
            transposeAdj[nbr].push_back(i);
        }
    }

    // Step3) calling dfs on transpose using topoSort and getting call count(no. odf scc)
    int sscCount = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            sscCount++;
            g->transposeDFS(top, visited, transposeAdj);
        }
    }

    // Step4) Print the result
    cout << "No. of strongly connected components(scc) in the graph are: " << sscCount << endl;

    return 0;
}