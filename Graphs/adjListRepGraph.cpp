#include<bits/stdc++.h>
using namespace std;

//simple undirected unweighted graph

//implementation using unordered_map<int,list<int>>
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

};

//implementation using vector<vector<int>>
class graph{
    public:
    int nodes;
    vector<vector<int>>adjList;

    graph(int n){
        nodes=n;
        adjList=vector<vector<int>>(n,vector<int>());
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
        int i;
        for(i=0;i<adjList[u].size();i++){
            if(adjList[u][i]==v){
                break;
            }
        }
        adjList[u].erase(adjList[u].begin()+i);

        for(i=0;i<adjList[v].size();i++){
            if(adjList[v][i]==u){
                break;
            }
        }
        adjList[v].erase(adjList[v].begin()+i);

        cout<<"Edge removed successfully."<<endl;
    }

};

int main(){

    graph*g=new graph(5);

    g->addEdge(0,4);
    g->addEdge(2,3);
    g->addEdge(1,0);

    g->printAdjList();

    g->removeEdge(0,4);
    g->removeEdge(2,3);

    g->printAdjList();
    
    return 0;
}