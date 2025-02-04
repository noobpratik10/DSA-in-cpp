#include<bits/stdc++.h>
using namespace std;
//first create graph class
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


    //Breadth First Search Traversal function
    void bfsTraversal(int node,unordered_map<int,bool>&visited){                                              
        queue<int>toVisit;                //make queue and insert srcnode
        toVisit.push(node);

        while(!toVisit.empty()){         //node ke neighbours q me daal & print queue until is empty
            int frontNode=toVisit.front();//get front node and print it
            toVisit.pop();

            if(!visited[frontNode]){
                cout<<frontNode<<" ";
                visited[frontNode]=true;

                for(auto i:adjList[frontNode]){    //push neighbours in queue
                    toVisit.push(i);
                }
            }      
        }
    }

};
int main(){
    
    //creating graph
    graph*g=new graph(5);
    g->addEdge(0,4);
    g->addEdge(2,3);
    g->addEdge(1,0);
    g->addEdge(3,1);
    g->addEdge(2,4);
    g->printAdjList();
    
    //creating necessary data structures
    unordered_map<int,bool>visited;
    for(int i=0;i<g->nodes;i++){
        visited[i]=false;
    }

    //call the function for every node (for it to work even for disconnected graph)
    cout<<"BFS Traversal of the graph is :"<<endl;
    for(int i=0;i<g->nodes;i++){
        if(!visited[i]){
            g->bfsTraversal(i,visited);
        }
    }cout<<endl;
    
    return 0;
}