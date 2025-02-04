#include<bits/stdc++.h>
using namespace std;
/*
Prims Algorithm:- Algorithm to get minimum spaning trree(MST) of the graph

Spanning Tree:- Graph with n nodes converted into tree with n nodes and n-1 edges

Min. Spanning Tree(MST):-Spanning tree with minimum cost of weight
*/

//creating an undirected weighted graph class
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

        p=make_pair(u,weight);
        adjList[v].push_back(p);

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

    //Prims Algorithm function
    void primsAlgo(int src,vector<int>&key,vector<bool>&mst,vector<int>&parent){
        //getting src node DSs
        parent[src]=-1;
        key[src]=0;

        //traversing every node
        for(int i=0;i<nodes;i++){
            //getting min. key node
            int mini=INT_MAX;
            int minNode;
            for(int j=0;j<nodes;j++){
                if(mst[j]==false && key[j]<mini){
                    mini=key[j];
                    minNode=j;
                }
            }

            //marking minNode in mst
            mst[minNode]=true;
            
            //updating key & parent for all the neighbours
            for(auto padosi:adjList[minNode]){
                int padosiNode=padosi.first;
                int padosiWeight=padosi.second;

                if(mst[padosiNode]==false && padosiWeight<key[padosiNode]){
                    key[padosiNode]=padosiWeight;
                    parent[padosiNode]=minNode;
                }
            }
        }
    }
};

int main(){
    //creating a grpah
    graph*g=new graph(5);
    g->addEdge(0,1,2);
    g->addEdge(0,3,6);
    g->addEdge(3,1,8);
    g->addEdge(1,2,3);
    g->addEdge(1,4,5);
    g->addEdge(4,2,7);
    g->printAdjList();

    //making & initializing necessary Data Structures
    vector<int>key(g->nodes,INT_MAX);
    vector<bool>mst(g->nodes,false);
    vector<int>parent(g->nodes,-1);

    //calling the function
    g->primsAlgo(0,key,mst,parent);

    //printing the result
    cout<<"MST: "<<endl;
    cout<<"child --> parent"<<endl;
    for(int i=0;i<g->nodes;i++){
        cout<<i<<" --> "<<parent[i]<<endl;
    }

    int cost=0;
    for(int i=0;i<key.size();i++){
        cost+=key[i];
    }
    cout<<"Cost of the MST is: "<<cost<<endl;
    
    return 0;
}