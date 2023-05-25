#include <bits/stdc++.h>
using namespace std;
// Only valid in DAGs
// uses BFS
// insert all degrees with indegree 0 in the queue
    vector<int>topo;
// Reduce indegrees of their neighbors i.e disconnect them and repeat the process
void TopoSort(unordered_map<int, vector<int>> graph,int n)
{
    // Make the indegree vector
    vector<int>indegree(n,0);

    for (auto x : graph)
    {
        for (int y : x.second)
        {
            indegree[y]++;
        }
    }
        queue<int> q;
     for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                q.push(i);

    while (!q.empty())
    {
            int curr = q.front();
            topo.push_back(curr);
            q.pop();
            for (auto nbh : graph[curr])
            {
                indegree[nbh]--;
                if(indegree[nbh]==0) q.push(nbh);
            }
    }
}
int main()
{
unordered_map<int, vector<int>> graph;
graph[0]={1};
graph[1]={0};
// graph[2]={0};
// graph[3]={4};
// graph[4]={5};
// graph[5]={};
int n = 2;
TopoSort(graph,n);
for(auto x: topo)
cout<<x<<" ";

    return 0;
}