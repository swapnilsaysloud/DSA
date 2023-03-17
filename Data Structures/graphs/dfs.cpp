#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
bool vis[N];
vector<int> g[N];
void dfs(int vertex)
{
    cout<<vertex<<endl;
    vis[vertex]=true;
    for(auto child:g[vertex])
    {
        if(vis[child]) continue;
        cout<<"par "<< vertex <<" child "<<child<<endl;
        dfs(child);
    }
  
}

int main(){
int n,e;
cin>>n>>e;

for(int i=0;i<e;i++)
{
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
}
dfs(1);
return 0;
}