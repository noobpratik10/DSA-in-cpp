#include<bits/stdc++.h>
using namespace std;

/*
Articulation Point:-A node in the graph whose removal makes the graph disconnected
                    (i.e.creates 2 or more components)

                    Also called cut vertices.
*/

//creating the grpah class
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

    //dfs funcn to find articulation point(ap)
    void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,
            unordered_map<int,bool>&visited,vector<int>&ap){
        //mark d.s of cur node
        visited[node]=true;
        disc[node]=low[node]=timer++;
        int child=0;    //for special check
                         
        //for all the neighbours
        for(auto nbr:adjList[node]){
            //if parent ignore
            if(nbr==parent){
                continue;
            }
            //if not visited make rec. call & check ap
            if(!visited[nbr]){
                dfs(nbr,node,timer,disc,low,visited,ap);
                // update low
                low[node]=min(low[node],low[nbr]);
                //ap check
                if(low[nbr]>=disc[node] && parent!=-1){
                    ap.push_back(node);
                }
                child++;
            }
            //if visited & not parent-->back edge
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }

        //special check
        if(parent==-1 && child>1){
            ap.push_back(node);
        }
    }
};
int main(){
    //creating the graph
    graph*g=new graph(5);
    g->addEdge(0,1);
    g->addEdge(0,3);
    g->addEdge(0,4);
    g->addEdge(3,4);
    g->addEdge(1,2);
    g->printAdjList();

    //making necessary D.S.
    int timer=0; 
    vector<int>disc(g->nodes,-1);    //discovery time
    vector<int>low(g->nodes,-1);     //lowest time
    int parent=-1;
    unordered_map<int,bool>visited;

    //make ans vector and pass in the dfs function
    vector<int>ap;
    for(int i=0;i<g->nodes;i++){
        if(!visited[i]){
            g->dfs(i,parent,timer,disc,low,visited,ap);
        }
    }

    //print the results
    cout<<"Articulation Points in the graph are: "<<endl;
    for(int i=0;i<ap.size();i++){
        cout<<ap[i]<<" ";
    }
    
    return 0;
}