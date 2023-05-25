#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
unordered_map<int,vector<int>>adj;
void dfs( int vertex)
{
    // Take action on vertex after entering the vertex
    cout<<vertex<<" "; 
    vis[vertex]=true;
for(int child : adj[vertex])
{
    //Take action on child node before entering the child node
    if(vis[child]) continue;
        // Take action after entering the child node
        dfs(child);
}
// Take action after exiting the vertex
}
int main(){
adj[1]={3,5};
adj[2]={3,6};
adj[3]={1,2,4,5,6};
adj[4]={3,6};
adj[5]={1,6};
adj[6]={2,4};
dfs(1);
return 0;
}