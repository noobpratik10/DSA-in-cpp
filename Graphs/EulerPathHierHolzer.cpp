#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int V;                               // Number of vertices
    unordered_map<int, vector<int>> adj; // Adjacency list

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void hierholzerRecursive(int u, vector<int> &eulerPath)
    {
        while (!adj[u].empty())
        {
            int v = adj[u].back();             // Get the last adjacent vertex
            adj[u].pop_back();                 // Remove the edge u->v
            hierholzerRecursive(v, eulerPath); // Recur for the next vertex
        }
        eulerPath.push_back(u); // Add vertex to Eulerian path/circuit
    }

    // Function to find and print Eulerian path or circuit
    void findEulerianPathOrCircuit()
    {
        // Check for Eulerian Path or Circuit
        int startVertex = 0;
        int oddDegreeCount = 0;

        // Count vertices with odd degree
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 != 0)
            {
                oddDegreeCount++;
                startVertex = i; // Start from a vertex with odd degree
            }
        }

        // Eulerian Circuit: All vertices have even degree (oddDegreeCount == 0)
        // Eulerian Path: Exactly two vertices have odd degree (oddDegreeCount == 2)
        if (oddDegreeCount != 0 && oddDegreeCount != 2)
        {
            cout << "No Eulerian Path or Circuit exists in the graph.\n";
            return;
        }

        vector<int> eulerPath;
        hierholzerRecursive(startVertex, eulerPath);

        // Reverse the result to get the path in the correct order
        reverse(eulerPath.begin(), eulerPath.end());

        // Print the result
        cout << "Eulerian Path/Circuit: ";
        for (int v : eulerPath)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main()
{
    int V = 5; // Number of vertices
    Graph g(V);

    // Example graph edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    g.findEulerianPathOrCircuit();

    return 0;
}
