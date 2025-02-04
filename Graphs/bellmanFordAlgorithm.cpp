
#include<bits/stdc++.h>
using namespace std;
/*
Bellman-Ford's Algorithm:- 
    Gives us shortest path from source node to all the nodes 
    in an connected directed weighted graph.
    It can also work on graph with negative weights.

Restrictions:-
    1) Doesnt work if negative cycle present.
*/

//creating a directed graph class
class graph{
    public:
    int nodes;
    unordered_map<int,list<pair<int,int>>>adjList;
    
    graph(int x){
        nodes=x;
    }

    void addEdge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adjList[u].push_back(p);

        cout<<"Edge created successfully!"<<endl;
    }

    void printAdjList(){
        cout<<"Adjacency List of the graph: "<<endl;
        for(auto node:adjList){
            cout<<node.first<<" --> ";
            for(auto padosi:node.second){
                cout<<"("<<padosi.first<<","<<padosi.second<<") , ";
            }cout<<endl;
        }
    }

    void removeEdge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adjList[u].remove(p);

        p=make_pair(u,weight);
        adjList[v].remove(p);

        cout<<"Edge removed successfully!"<<endl;
    }

    void bellmanFordAlgo(int src,vector<int>&dist){
        //create edges vector from adjList
        vector<vector<int>>edges;
        for(auto node:adjList){
            for(auto connection:node.second){
                vector<int>edge;
                edge.push_back(node.first);
                edge.push_back(connection.first);
                edge.push_back(connection.second);
                edges.push_back(edge);
            }
        }
        //make dist of src node 0
        dist[src]=0;

        //nodes-1 times update use formula on each edge
        for(int i=0;i<nodes-1;i++){
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                //update dist 
                if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }

        //check for negative cycle by applying formula once more
        bool negCyclePresent=false;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
                negCyclePresent=true;
                break;
            }
        }
        if(negCyclePresent){
            cout<<"Negative cycle present in graph."<<endl;
        }
        else{
            cout<<"Negative cycle absent in graph."<<endl;
        }
    }
};

int main(){
    //creating a directed graph & edges. 
    graph*g=new graph(3);
    g->addEdge(0,1,2);
    g->addEdge(0,2,2);
    g->addEdge(1,2,-1);
    g->printAdjList();

    //calling the function for src node
    cout<<"Enter the source node: "<<endl;
    int src;
    cin>>src;
    vector<int>dist(g->nodes,INT_MAX);
    g->bellmanFordAlgo(src,dist);

    //printin ght ans
    cout<<"Shortest distance from "<<src<<" to all nodes is: "<<endl;
    cout<<"Node --> Distance"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<i<<" --> "<<dist[i]<<endl;
    }

    return 0;
}