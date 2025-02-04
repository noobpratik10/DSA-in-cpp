#include <bits/stdc++.h>
using namespace std;
/*
Bridge:-Edge of the graph whose removal makes the graph disconnected
        (i.e. increases the connected components of the graph)
*/

// creating the grpah class
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

    // geting bridges function
    void getBridges(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
                    vector<vector<int>> &bridges, unordered_map<int, bool> &visited)
    {
        // update ds of current node
        visited[node] = true;
        disc[node] = low[node] = timer++;

        // for all the neighbours
        for (auto nbr : adjList[node])
        {
            // if ndr is parent the ignore
            if (nbr == parent)
            {
                continue;
            }
            // recursive call if unvisited nbr
            else if (!visited[nbr])
            {
                getBridges(nbr, node, timer, disc, low, bridges, visited);
                // update low
                low[node] = min(low[node], low[nbr]);
                // check bridge
                if (low[nbr] > disc[node])
                {
                    vector<int> bridge;
                    bridge.push_back(node);
                    bridge.push_back(nbr);
                    bridges.push_back(bridge);
                }
            }
            // node already visited & not parent
            // back edge
            else
            {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
};
int main()
{
    // creating a graph
    graph *g = new graph(5);
    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
    g->printAdjList();

    // creating necessary data structures
    int timer = 0;
    vector<int> disc(g->nodes, -1);   // discovery time
    vector<int> low(g->nodes, -1);    // lowest time
    int parent = -1;                  // parent
    unordered_map<int, bool> visited; // visited array

    // make result array and call the function for all components (dfs approach)
    vector<vector<int>> bridges;
    for (int i = 0; i < g->nodes; i++)
    {
        if (!visited[i])
        {
            g->getBridges(i, parent, timer, disc, low, bridges, visited);
        }
    }

    // print the result
    cout << "Bridges in the graph are: " << endl;
    for (int i = 0; i < bridges.size(); i++)
    {
        cout << bridges[i][0] << " -- " << bridges[i][1] << endl;
    }

    return 0;
}