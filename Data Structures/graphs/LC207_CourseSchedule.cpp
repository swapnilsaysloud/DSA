#include <bits/stdc++.h>
using namespace std;
int allVis(vector<bool>vis)
{
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i]==false) return i;
    }
    return -1;
}
bool cycle(unordered_map<int, vector<int>> graph, int source)
{
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        for (int neighbour : graph[vertex])
        {
            if (visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
            else{
                return true;
            }
        }
    }
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // numCourses: Number of nodes
    // pq: directed edges
    vector<bool> visited(numCourses, false);
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    bool hasCycle = cycle(adj,0);
    if(hasCycle) return false;
    return true;
}
int main()
{

    return 0;
}