#include <bits/stdc++.h>
using namespace std;
// const int N = 20;
const int INF = 1e9 + 10;
// For finding shortest path
// Use either set (Fastest) or Priority queue
// Not applicable to graphs with negative weight cycles
void printShortestPath(vector<vector<int>>paths,int dest)
{
  for(auto x: paths[dest]) cout<<x<<"->";
}
vector<int> Dijkstra(unordered_map<int, vector<pair<int, int>>> adj, int s1)
{
    int N = adj.size();
    vector<int> dist(N, INF);
    vector<int> vis(N, INF);
    set<pair<int, int>> st;
    // dist,node
    st.insert({0, s1});
    vector<vector<int>> shortestPaths(N);
    while (st.size() > 0)
    {
        auto node = *st.begin(); // Min element in node
        int v = node.second;
        int distance = node.first;
        st.erase(st.begin());
        // Agar ek baar koi node queue se nikal gayi to use dobara process nahi karna h
        if (vis[v] == 1)
            continue;
        vis[v] = 1;
        for (auto child : adj[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (wt + distance < dist[child_v])
            {
                dist[child_v] = wt + distance;
                st.insert({dist[child_v], child_v});
                // Update the shortest path to the child node
                shortestPaths[child_v] = shortestPaths[v]; // Copy the path from the parent node
                shortestPaths[child_v].push_back(child_v); // Add the child node to the path
            }
        }
    }
    dist[0]=0;
  printShortestPath(shortestPaths,1);
    return dist;
}
int main()
{
    unordered_map<int, vector<pair<int, int>>> adj;
    // node,weight pair
    // adj[0] = {{1, 4}, {2, 4}};
    // adj[1] = {{0, 4}, {2, 2}};
    // adj[2] = {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}};
    // adj[3] = {{2, 3}, {5, 2}};
    // adj[4] = {{2, 1}, {5, 3}};
    // adj[5] = {{2, 6}, {3, 2}, {4, 3}};

    adj[0] = {{2, 1}, {3, 1}};
    adj[1] = {{4,1}};
    adj[2] = {{0, 1}};
    adj[3] = {{0, 1}, {4,1}};
    adj[4] = {{3, 1}, {1, 1}};
    vector<int> a = Dijkstra(adj, 0);
    for (auto x : a)
        cout << x << " ";
    return 0;
}
// 4,4,7,5,8