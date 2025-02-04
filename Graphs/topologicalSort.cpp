#include<bits/stdc++.h>
using namespace std;
/*

-->DAG Graph:- A directed graph which contains no cycles.

-->Topological Sort:- Linear ordering of vertices such that if there exists
                   an edge between u-->v, then u should lie before v in
                   the ordering.

-->Approaches:- 
                1) using Depth First Search (DFS)
                2) using Kahn's Algorithm
*/

//creating DAG class
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

    //1) topological order using DFS logic
    void topoSortDFS(int node,unordered_map<int,bool>&visited,stack<int>&st){
        
        visited[node]=true;

        for(auto neighbour:adjList[node]){
            if(!visited[neighbour]){
                topoSortDFS(neighbour,visited,st);
            }
        }
        st.push(node);
    }

    // 2)topological order using Kahn's Algorithm
    void topoSortKahn(vector<int>&inDegree,queue<int>&q,vector<int>&topoOrder){
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topoOrder.push_back(front);

            for(auto neighbour:adjList[front]){
                inDegree[neighbour]--;

                if(inDegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
    }
};
int main(){
    //creating a DAG graph
    graph*g=new graph(5);
    g->addEdge(0,4);
    g->addEdge(2,3);
    g->addEdge(1,0);
    g->addEdge(4,3);
    g->addEdge(1,2);
    g->printAdjList();


    // 1) using DFS logic
    /*
    calling topological sort function for all components
    unordered_map<int,bool>visited;
    stack<int>st;
    for(int i=0;i<g->nodes;i++){
        if(!visited[i]){
            g->topoSortDFS(i,visited,st);
        }
    }

    //get anwer in vector from stack
    vector<int>topoOrder;
    while(!st.empty()){
        topoOrder.push_back(st.top());
        st.pop();
    }
    */

    //2)using khan's algorithm
    //find indegrees of all the nodes
    vector<int>inDegree(g->nodes,0);
    for(int i=0;i<g->nodes;i++){
        for(auto j:g->adjList[i]){
            inDegree[j]++;
        }
    }

    //queue banake 0 indergree wale insert karo
    queue<int>q;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    //bfs karo
    vector<int>topoOrder;
    g->topoSortKahn(inDegree,q,topoOrder);

    cout<<"Topological Order of the DAG graph is :"<<endl;
    for(int i=0;i<topoOrder.size();i++){
        cout<<topoOrder[i]<<" ";
    }cout<<endl;

    return 0;
}