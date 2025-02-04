/*
Dijkstra's Algorithm:- Gives us shortest path from source node to all the nodes
                       in an connected undirected weighted graph.

Restrictions:-
            1) Doesnt work on negative weights.
            2) Only works on simple graph.
*/

#include <bits/stdc++.h>
using namespace std;

// creating the graph class
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

        p = make_pair(u, weight);
        adjList[v].push_back(p);

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

    // Dijkstra's Algorithm using set
    void dijkstraAlgoSet(int src, vector<int> &dist, set<pair<int, int>> &st)
    {
        // update src & push in set
        dist[src] = 0;
        pair<int, int> p = make_pair(0, src);
        st.insert(p);

        while (!st.empty())
        {
            auto top = *(st.begin()); // get top element from set(with min. distance)
            int topDist = top.first;
            int topNode = top.second;
            st.erase(st.begin());

            for (auto padosi : adjList[topNode])
            { // update the dist. of all the neighbours with topDist
                if (topDist + padosi.second < dist[padosi.first])
                {

                    // erase prev record from set of neighbour with larger dist.
                    auto record = st.find(make_pair(dist[padosi.first], padosi.first));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    // update & insert new record with new dist
                    dist[padosi.first] = topDist + padosi.second;
                    st.insert(make_pair(dist[padosi.first], padosi.first));
                }
            }
        }
    }

    // Dijkstra's Algorithm using priority queue (min Heap)
    void dijkstraAlgoPQ(int src, vector<int> &dist, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &minHeap)
    {

        // update dist src and push in pq
        dist[src] = 0;
        minHeap.push(make_pair(dist[src], src));

        while (!minHeap.empty())
        {
            auto top = minHeap.top(); // get node with min. dist
            minHeap.pop();
            int topDist = top.first;
            int topNode = top.second;

            for (auto padosi : adjList[topNode])
            { // update dist of every neighbour
                if (topDist + padosi.second < dist[padosi.first])
                {
                    // //delete prev record of padosi from pq
                    // auto record=minHeap.find(make_pair(dist[padosi.first],padosi.first));
                    // if(record!=minHeap.end()){
                    //     minHeap.erase(record);
                    // }
                    // create and insert new record
                    dist[padosi.first] = topDist + padosi.second;
                    minHeap.push(make_pair(dist[padosi.first], padosi.first));
                }
            }
        }
    }
};

int main()
{
    // creating a graph
    graph *g = new graph(5);

    g->addEdge(1, 2, 3);
    g->addEdge(1, 4, 1);
    g->addEdge(2, 0, 1);
    g->addEdge(1, 0, 7);
    g->addEdge(1, 3, 5);
    g->addEdge(4, 3, 7);
    g->addEdge(0, 3, 2);
    g->printAdjList();

    // get the source from the user input
    int src;
    cout << "Enter the source node here: ";
    cin >> src;

    // djkstra's algorithm funcn using set
    vector<int> dist(g->nodes, INT_MAX);
    set<pair<int, int>> st; //(dist.,node.)
    g->dijkstraAlgoSet(src, dist, st);

    // djkstra's algorithm using min heap(priority queue)
    vector<int> dist(g->nodes, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //(dist,node)
    g->dijkstraAlgoPQ(src, dist, minHeap);

    // print the result
    cout << "Distances from " << src << " to all nodes are: " << endl;
    cout << "Nodes -->  Distances" << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " --> " << dist[i] << endl;
    }

    return 0;
}