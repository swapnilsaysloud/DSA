#include <bits/stdc++.h>
using namespace std;
int ShortestPathLength(vector<vector<int>> graph, int source, int dest)
{
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    vector<int> distance(vertices, 0);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if (vertex == dest)
            break;
        for (int neighbour : graph[vertex])
        {
            if (visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push(neighbour);
                distance[neighbour] = 1 + distance[vertex];
            }
        }
    }
    return distance[dest];
}
void ShortestPath(vector<vector<int>> graph, int source, int dest)
{
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if (vertex == dest)
            break;
        for (int neighbour : graph[vertex])
        {
            if (visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = vertex;
            }
        }
    }
    int v = dest;
    while (v != -1)
    {
        cout << v << " ";
        v = parent[v];
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
    int dest = 3;
    cout << "Shortest Path length is ";
    cout << ShortestPathLength(graph, source, dest) << endl;
    cout << "Path is: ";
    ShortestPath(graph, source, dest);
    return 0;
}