#include <bits/stdc++.h>
using namespace std;
int Dijkstra(unordered_map<int, vector<pair<int, int>>> adj, int s1, int dest)
{
    int N = adj.size();
    vector<int> dist(N, 100);
    vector<int> vis(N, 100);
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
    dist[0] = 0;
    return dist[dest];
}
vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<vector<int>> ans(1);

    for (int i = 0; i < edges.size(); i++)
    {
        if(edges[i][2]==-1) continue;
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
        cout<<"edgesModified && adj Made"<<endl;
    for (auto x : adj)
    {
        cout << x.first << endl;
        for (auto y : x.second)
        {
            cout << y.first << " " << y.second;
        }
        cout << endl;
    }
    int sum = Dijkstra(adj, source, destination);
    cout<<"sum: "<<sum<<endl;
    if (sum < target)
        return ans;
    if (sum == target)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][2] == -1)
                edges[i][2] = 1e9;
        }
        return edges;
    }
    for (auto x : adj)
    {
        for (auto y : x.second)
        {
            if (y.second == -1)
            {
                y.second == 1;
                int distance = Dijkstra(adj, source, destination);
                if (distance <= target)
                {
                    y.second += target - distance;
                    for (int i = 0; i < edges.size(); i++)
                    {
                        if (edges[i][2] == -1)
                            edges[i][2] = 1e9;
                    }
                    return edges;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> edges(4);
    edges[0] = {4, 1, -1};
    edges[1] = {2, 0, -1};
    edges[2] = {0, 3, -1};
    edges[3] = {4, 3, -1};
    cout<<"edgesmade"<<endl;
    vector<vector<int>> ans = modifiedGraphEdges(5, edges, 0, 1, 5);
    cout<<"Printig ans"<<endl;
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
