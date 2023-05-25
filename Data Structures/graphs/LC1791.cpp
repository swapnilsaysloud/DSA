#include<bits/stdc++.h>
using namespace std;
void printadj(vector<vector<int>>& adj)
{
    int row = adj.size();
    for(int i=0;i<row;i++)
    {
        cout<<adj[i][0]<<": ";
        for(int j=1;j<adj[i].size();j++)
        {
            cout<<adj[i][j];
        }
        cout<<endl;
    }
}
 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0 || source == destination) return true; 
        vector<vector<int>>adj(n,vector<int>(0));
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        printadj(adj);
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        visited[source]=true;
        while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto neighbour: adj[top])
        {
          if(visited[neighbour]==false)
          {
              if(neighbour==destination) return true;
              q.push(neighbour);
              visited[neighbour]=true; 
          }
        }
    }
    return false;

    }
int main(){
    vector<vector<int>>a = {{2,9},{7,8},{5,9},{7,2},{3,8},{2,8},{1,6},{3,0},{7,0},{8,5}};
cout<<validPath(10,a,1,0);
return 0;
}