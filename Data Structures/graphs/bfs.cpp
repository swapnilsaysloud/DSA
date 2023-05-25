#include <bits/stdc++.h>

using namespace std;
void bfs(vector<vector<int>> graph, int source)
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
        }
    }
}
int main()
{
    // Hardcoded data
    int numVertices = 7;
    vector<vector<int>> graph(numVertices);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5, 6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};

    int source = 5;

    cout << "BFS traversal starting from vertex " << source << ": ";
    bfs(graph, source);
    /*
    // To make it dynamic
    int vertices,edges;
    cin>>vertices>>edges;
      vector<vector<int>> graph_dynamic(vertices);
      for(int i=0;i<edges;i++)
      {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
      }
      */

    return 0;
}