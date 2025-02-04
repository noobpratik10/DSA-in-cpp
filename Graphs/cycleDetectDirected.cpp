#include <bits/stdc++.h>
using namespace std;
// cycle detection in directed graph
// Condition:- if the nbr is already visited && its visited in current rec stack
// Algorithm:- DFS Traversal

class Solution
{
public:
    bool dfs(int curr, int V, vector<int> &parent, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[])
    {
        visited[curr] = true;
        dfsVisited[curr] = true;

        bool ans = false;
        for (auto nbr : adj[curr])
        {
            if (visited[nbr] && dfsVisited[nbr] && parent[nbr] != curr && parent[nbr] != -1)
            {
                return true;
            }
            else
            {
                if (!visited[nbr])
                {
                    ans = ans || dfs(nbr, V, parent, visited, dfsVisited, adj);
                }
            }
        }
        dfsVisited[curr] = false;
        return ans;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        bool ans = false;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                vector<bool> dfsVisited(V, false);
                ans = ans || dfs(i, V, parent, visited, dfsVisited, adj);
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);

            Solution obj;
            cout << obj.isCyclic(V, adj) << "\n";
        }
    }
    return 0;
}
