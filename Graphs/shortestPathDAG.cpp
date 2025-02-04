#include<bits/stdc++.h>
using namespace std;
// shortest path in DAG(Directed acyclic graph) & weighted graph
/*
    step 1)Get the topological sort of the graph.
    step 2)Utilize topoSort to update distance array.
*/
//creating a weighted DAG class
class graph{
    public:
    int nodes;
    unordered_map<int,list<pair<int,int>>>adjList;   //node--->neighbours(node,weight)

    graph(int x){
        nodes=x;
    }

    void addEdge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adjList[u].push_back(p);
        cout<<"Edge created successfully!"<<endl;
    }

    void printAdjList(){
        cout<<"Adjacency List of the graph is: "<<endl;
        for(auto i:adjList){
            cout<<i.first<<" --> ";
            for(auto neighbour:i.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second<<")"<<" , ";
            }cout<<endl;
        }
    }

    void removeEdge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adjList[u].remove(p);
        cout<<"Edge removed successfully!"<<endl;
    }

    //toposort function
    void topoSortDFS(int node,unordered_map<int,bool>&visited,stack<int>&topoOrder){
        visited[node]=true;    //node ko visited mark karo

        for(auto neighbour:adjList[node]){    //har unvisited neighbour kelie funcn call karo
            if(!visited[neighbour.first]){
                topoSortDFS(neighbour.first,visited,topoOrder);
            }
        }

        topoOrder.push(node);          //stack me dalo agar khi bhi nhi sakte to      
    }

    //shortest path f=getter funcn
    void getShotrestPath(int src,vector<int>&distance,stack<int>&topoOrder){
        distance[src]=0;          //source ka dist 0 mark karo

        //top order ke sare el. nikalte jao
        while(!topoOrder.empty()){
            int node=topoOrder.top();
            topoOrder.pop();
                                                         //if element ka dist. is not infinity               
            if(distance[node]!=INT_MAX){                 //har element ke dist. update karte jao
                for(auto neighbour:adjList[node]){    
                    // distance[neighbour.first]=min(distance[neighbour.first],distance[node]+neighbour.second);
                    if(distance[node]+neighbour.second<distance[neighbour.first]){
                        distance[neighbour.first]=distance[node]+neighbour.second;
                    }
                }
            }
            
        }
    }
};
int main(){
    //create a DAG graph
    graph*g=new graph(6);

    g->addEdge(0,1,5);
    g->addEdge(0,2,3);
    g->addEdge(1,2,2);
    g->addEdge(1,3,6);
    g->addEdge(2,3,7);
    g->addEdge(2,4,4);
    g->addEdge(2,5,2);
    g->addEdge(3,4,-1);
    g->addEdge(4,5,-2);
    g->printAdjList();

    //get shortest path from the source to all the nodes
    int src;
    cout<<"\nEnter the source node here: "<<endl;
    cin>>src;

    //Step 1)get the topological sort of the graph
    unordered_map<int,bool>visited;
    stack<int>topoOrder;
    for(int i=0;i<g->nodes;i++){     //call the topo sort function for all the components
        if(!visited[i]){
            g->topoSortDFS(i,visited,topoOrder);
        }
    }

    //step 2)Utilize the topoOrder to update the distance array
    vector<int>distance(g->nodes,INT_MAX);
    g->getShotrestPath(src,distance,topoOrder);
    
    //step 3)Print the distace array
    cout<<"\nDistances from "<<src<<" node to all the nodes are: "<<endl;
    cout<<"Node --> Distance"<<endl;
    for(int i=0;i<g->nodes;i++){
        if(distance[i]==INT_MAX){
            cout<<i<<" --> "<<"INFINITY"<<endl;    
        }
        else{
            cout<<i<<" --> "<<distance[i]<<endl;
        }
        
    }

    return 0;
}