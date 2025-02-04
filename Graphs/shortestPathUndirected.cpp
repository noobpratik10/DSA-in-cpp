#include<bits/stdc++.h>
using namespace std;
/*Shortest Path in an undirected unweighted graph*/

//creating graph class
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

};

//function to find shortest path using BFS algorithm
vector<int>findPath(int V,unordered_map<int,list<int>>adjList,int src,int dest){
    //make necessary DS
    unordered_map<int,int>parent; //child->parent
    unordered_map<int,bool>visited;
    queue<int>q;

    //put src in queue
    q.push(src);
    visited[src]=true;
    parent[src]=-1;

    //do bfs --> to build parent DS
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neighbour:adjList[front]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                parent[neighbour]=front;
                q.push(neighbour);
            }
        }
    }

    //make ans
    vector<int>shortestPath;
    int curNode=dest;
    shortestPath.push_back(curNode);
    while(curNode!=src){
        curNode=parent[curNode];
        shortestPath.push_back(curNode);
    }
    reverse(shortestPath.begin(),shortestPath.end());

    //return ans
    return shortestPath;
}
int main(){
    //creating a graph
    graph*g=new graph(8);
    g->addEdge(0,1);
    g->addEdge(1,4);
    g->addEdge(4,7);
    g->addEdge(0,2);
    g->addEdge(2,7);
    g->addEdge(0,3);
    g->addEdge(3,5);
    g->addEdge(5,6);
    g->addEdge(6,7);
    g->printAdjList();
    
    //find shortest path
    vector<int>shortestPath;
    int src=0,dest=7;
    shortestPath=findPath(g->nodes,g->adjList,src,dest);

    //print shortest path
    cout<<"Shortest path from "<<src<<" to "<<dest<<" is :"<<endl;
    for(int i=0;i<shortestPath.size();i++){
        cout<<shortestPath[i]<<"  ";
    }cout<<endl;

    return 0;
}

