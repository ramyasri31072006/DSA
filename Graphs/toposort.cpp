//**********TOPOLOGICAL_SORT**************
// use to sort the graph based on indegree
//To use topo sort the graph must not contain cycle and it should be directed graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int>adj[vertices+1];//create an adjancency list for every vertix
    vector<int>Indegree(vertices+1,0);//create an array to store indegree for every vertix
    int u,v;
    for(int i=0;i<edges;i++){//assign values into adjacency list and indegree vector
        cin>>u>>v;
        adj[u].push_back(v);
        Indegree[v]++;
    }
    queue<int>Q;//push all the vertix having indegree '0' into queue 
    for(int i=1;i<Indegree.size();i++){
        if(Indegree[i]==0){
            Q.push(i);
        }
        
    }
    //iteratively remove vertix from queue and adds to sorted list
    //and decrease its neighbhours indegree. if it is '0' then push into queue 
    //continue this process until queue is empty;
    while(!Q.empty()){
        int idx=Q.front();
        cout<<idx<<" ";
        Q.pop();
        for(auto i: adj[idx]){
            Indegree[i]--;
            if(Indegree[i]==0){
                Q.push(i);
            }
        }
    }

}
