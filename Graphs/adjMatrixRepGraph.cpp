#include<bits/stdc++.h>
using namespace std;

// Simple undirected unweighted graph

class graph{
    public:
    int nodes;
    vector<vector<int>>adjMatrix;
    
    graph(int n){
        nodes=n;
        adjMatrix=vector<vector<int>>(n,vector<int>(n,0));
    }

    void addEdge(int u,int v){
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
        cout<<"Edge created successfully."<<endl;
    }

    void printMatrix(){
        cout<<"Adj. Matrix of graph is as follows:"<<endl;
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                cout<<adjMatrix[i][j]<<" ";
            }cout<<endl;
        }
    }

    void removeEdge(int u,int v){
        adjMatrix[u][v]=0;
        adjMatrix[v][u]=0;
        cout<<"Edge removed successfully."<<endl;
    }
};

int main(){

    graph*g=new graph(5);
    
    g->addEdge(0,4);
    g->addEdge(2,3);
    g->addEdge(1,0);

    g->printMatrix();

    g->removeEdge(3,2);
    g->removeEdge(1,0);

    g->printMatrix();

    return 0;
}