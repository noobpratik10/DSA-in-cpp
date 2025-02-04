#include<bits/stdc++.h>
using namespace std;

//creating a graph
class graph{
    public:
    int nodes;
    unordered_map<int,list<int>>adjList;

    graph(int n){
        nodes=n;
        for(int i=0;i<nodes;i++){
            list<int>l;
            pair<int,list<int>>p=make_pair(i,l);
            adjList.insert(p);
        }
    }

    void addEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        cout<<"Edge created successfully."<<endl;
    }

    void printAdjList(){
        cout<<"Adjacent List of the graph is :"<<endl;
        for(int i=0;i<nodes;i++){
            cout<<i<<"-->";
            for(auto j:adjList[i]){
                cout<<j<<" ";
            }cout<<endl;
            
        }
    }

    void removeEdge(int u,int v){
        adjList[u].remove(v);
        adjList[v].remove(u);

        cout<<"Edge removed successfully."<<endl;
    }

    //DFS Traversal function --->using recursion
    void dfsTraversal(int node,unordered_map<int,bool>&visited){
        //base case
        if(visited[node]){
            return;
        }

        cout<<node<<" ";
        visited[node]=true;
        for(auto i:adjList[node]){
            dfsTraversal(i,visited);
        }
    }

};

int main(){
    
    graph*g=new graph(5);

    g->addEdge(0,4);
    g->addEdge(2,3);
    g->addEdge(1,0);
    g->addEdge(0,2);
    g->addEdge(3,1);
    g->printAdjList();

    //make necessary Ds
    unordered_map<int,bool>visited;
    for(int i=0;i<g->nodes;i++){
        visited[i]=false;
    }

    //call funcn for every unvisited node (to work for disconnected graph)
    cout<<"DFS Traversal of the graph is :"<<endl;
    for(int i=0;i<g->nodes;i++){
        if(!visited[i]){
            g->dfsTraversal(i,visited);
        }
    }

    return 0;
}