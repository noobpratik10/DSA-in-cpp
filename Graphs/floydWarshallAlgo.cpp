
#include <bits/stdc++.h>
using namespace std;
/*
Floyd Warshall's Algorithm:-
    -- Gives us shortest paths from ALL THE NODES to ALL THE NODES
    in an connected directed weighted graph.
    -- It can also work on graph with negative weights.
    -- Can be used to detect negative cycles
    -- Its not much of a intuitive algorithm but a simple brute force using 3 loops
    -- TC:- O(n^3)
    -- SC:-O(1)

Restrictions:-
    1) Doesnt work if negative cycle present.
*/

// creating a directed graph class
class graph
{
public:
    int nodes;
    unordered_map<int, list<pair<int, int>>> adjList;

    graph(int x)
    {
        nodes = x;
    }

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);

        cout << "Edge created successfully!" << endl;
    }

    void printAdjList()
    {
        cout << "Adjacency List of the graph: " << endl;
        for (auto node : adjList)
        {
            cout << node.first << " --> ";
            for (auto padosi : node.second)
            {
                cout << "(" << padosi.first << "," << padosi.second << ") , ";
            }
            cout << endl;
        }
    }

    void removeEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].remove(p);

        p = make_pair(u, weight);
        adjList[v].remove(p);

        cout << "Edge removed successfully!" << endl;
    }

    void floydWarshallAlgo(vector<vector<int>> &dist)
    {
        // modify dist matrix acc to adjList
        for (auto curr : adjList)
        {
            int u = curr.first;
            for (auto l : curr.second)
            {
                int v = l.first;
                int w = l.second;
                dist[u][v] = w;
            }
        }
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
            }
        }

        // use three loops - via , from , to
        for (int via = 0; via < nodes; via++)
        {
            for (int i = 0; i < nodes; i++)
            {
                for (int j = 0; j < nodes; j++)
                {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        // check for negative cycle by checking if dist negative
        bool negCyclePresent = false;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (dist[i][j] < 0)
                {
                    negCyclePresent = true;
                    break;
                }
            }
        }
        if (negCyclePresent)
        {
            cout << "Negative cycle present in graph." << endl;
        }
        else
        {
            cout << "Negative cycle absent in graph." << endl;
        }
    }
};

int main()
{
    // creating a directed graph & edges.
    graph *g = new graph(5);

    g->addEdge(1, 2, 3);
    g->addEdge(1, 4, 1);
    g->addEdge(2, 0, 1);
    g->addEdge(1, 0, 7);
    g->addEdge(1, 3, 5);
    g->addEdge(4, 3, 7);
    g->addEdge(0, 3, 2);
    g->printAdjList();

    // calling the function
    vector<vector<int>> dist(g->nodes, vector<int>(g->nodes, INT_MAX));
    g->floydWarshallAlgo(dist);

    // printin ght ans
    for (int src = 0; src < g->nodes; src++)
    {
        cout << "Shortest distance from " << src << " to all nodes is: " << endl;
        cout << "Node --> Distance" << endl;
        for (int i = 0; i < g->nodes; i++)
        {
            cout << i << " --> " << dist[src][i] << endl;
        }
        cout << endl;
    }

    return 0;
}