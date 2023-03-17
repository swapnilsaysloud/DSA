#include<bits/stdc++.h>
using namespace std;
const int N=1e5 +10;
map<int, list<int> > adj;
vector<int>ans;
 vector<bool>visited;
void printVec()
{
    for(int i:ans)
    {
        cout<<i<<" ";
    }
}
void DFS(int a , int b,int n)
{
 visited[a]=true;
 ans.push_back(a);
 if(a==b)
 {
    printVec();
    return;
 }
 list<int>::iterator i;
 for(auto i=adj[a].begin();i!=adj[a].end();i++)
 {
    if(visited[*i]==false)
    {
        visited[*i]=true;
        DFS(*i,b,n);
    }
 }
}
int main(){
int n,e;
cin>>n;
cin>>e;
for(int i=0;i<e;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);  
}
    cout<<"find path"<<endl;
    int a,b;
    cin>>a>>b;
    DFS(a,b,n);
return 0;
}