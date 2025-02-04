#include <bits/stdc++.h>
using namespace std;
// Cycle detection in undirected graph
//  1)Using BFS Traversal
//  2)Using DFS Traversal

// creating graph class
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
        adjList[v].push_back(u);
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
    // iscyclic funcn using bfs
    bool isCyclicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
    {
        queue<int> toVisit; // queue banake src node dalo
        toVisit.push(node);
        visited[node] = 1;
        parent[node] = -1;

        while (!toVisit.empty())
        {
            int frontNode = toVisit.front(); // queue ka frontNode nikalo
            toVisit.pop();
            // visited[frontNode]=true;

            for (auto neighbour : adjList[frontNode])
            { // each neighbour queue me dalo
                if (visited[neighbour] == true && neighbour != parent[frontNode])
                { // check agar neighbour pe cycle hai
                    return true;
                }
                else if (!visited[neighbour])
                {
                    toVisit.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }

        return false;
    }

    // isCyclic using DFS Traversal
    bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited)
    {

        visited[node] = true;

        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                bool cycleDetected = isCyclicDFS(i, node, visited);
                if (cycleDetected)
                {
                    return true;
                }
            }
            else if (visited[i] && i != parent)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    // creating graph
    graph *g = new graph(5);
    g->addEdge(0, 4);
    g->addEdge(2, 3);
    g->addEdge(1, 0);
    g->addEdge(4, 3);
    g->addEdge(1, 2);
    g->printAdjList();

    bool isCyclic = false;
    // 1) Cycle detection using BFS Traversal
    unordered_map<int, bool> visited;
    for (int i = 0; i < g->nodes; i++)
    {
        visited[i] = false;
    }
    unordered_map<int, int> parent; // child->parent
    for (int i = 0; i < g->nodes; i++)
    {
        if (!visited[i])
        {
            isCyclic = g->isCyclicBFS(i, visited, parent);
            if (isCyclic)
            {
                break;
            }
        }
    }

    // 2) Cycle detection using DFS Traversal
    unordered_map<int, bool> visited;
    for (int i = 0; i < g->nodes; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < g->nodes; i++)
    {
        if (!visited[i])
        {
            isCyclic = g->isCyclicDFS(i, -1, visited);
            if (isCyclic)
            {
                break;
            }
        }
    }

    if (isCyclic)
    {
        cout << "Graph is Cyclic" << endl;
    }
    else
    {
        cout << "Graph is not Cyclic." << endl;
    }

    return 0;
}