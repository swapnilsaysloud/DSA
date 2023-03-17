#include <bits/stdc++.h>
using namespace std;

int bfs(int source, int sink, vector<int>& parent, vector<vector<int>>& residualGraph) {
    fill(parent.begin(), parent.end(), -1);
    int V = residualGraph.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av=0; av < V; av++) {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}

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

int ford_fulkerson(vector<vector<int>>& graph, int source, int sink) {
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualGraph = graph;
    int min_cap = 0, max_flow = 0;
    while (min_cap = bfs(source, sink, parent, residualGraph)) {
        max_flow += min_cap;
        int u = sink;
        while (u != source) {
            int v = parent[u];
            residualGraph[u][v] += min_cap;
            residualGraph[v][u] -= min_cap;
            u = v;
        }
    }
    return max_flow;
}

void addEdge(vector<vector<int>>& graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{
    int V = 6;
    vector<vector<int>> graph(V, vector<int> (V, 0));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 4, 5, 6);
    
    cout << "Maximum Flow: " << ford_fulkerson(graph, 0, 5) << endl;
    return 0;
}
/*Making adjacency matrix of a weighted graph

   int ver, edg;
    cout << "Enter the number of vertices: "<<endl;
    cin >> ver;
    cout << " Enter the number of edges: "<<endl;
    cin >> edg;
    cout<<"Enter each edge along with the time required to burn it [format: starting point, end point, edgeweight"<<endl;
    for (int i = 0; i < edg; i++)
    {
        int v1, v2, wt;
        cin >> v1;
        cin >> v2;
        cin >> wt;
       graph[v1][v2]=wt;
    }
*/
/*
Making adjacency list
vector<int> g[N];
for(int i=0;i<e;i++)
{
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
}
*/
/*Dijkstra's algorithmm
#define V 9
 
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist, V);
}
 
// driver program to test above function

*/