#include <bits/stdc++.h>
using namespace std;

pair<int, int> ReturnTarget(unordered_map<int, vector<pair<int, int>>> adj, int s1, int dest)
{
    int N = adj.size();
    vector<int> dist(N, 100);
    vector<int> vis(N, 100);
    vector<vector<int>> shortestPaths(N);
    set<pair<int, int>> st;
    // dist,node
    st.insert({0, s1});
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
                shortestPaths[child_v] = shortestPaths[v];
                shortestPaths[child_v].push_back(child_v);
            }
        }
    }
    int x = shortestPaths[dest][0];
    cout << dist[dest] << " " << x;
    return {dist[dest], x};
}

vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
{
    // shortest path -> dijkstra -ve -> +ve (bfs)
    // sum of edge value from start to dest == target : dist[dest] == target
    // put all the edge values with -1 == 1
    // find the shortest path using dijkstra and also find sum of edge values
    // if target < sum return empty array
    // find target - sum
    // add it to any edge from shortest path
    cout<<"EnteredFunction"<<endl;
    unordered_map<int, vector<pair<int, int>>> adj;

    vector<vector<int>> ans;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i][2] == -1)
            edges[i][2] = 1;
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
    cout<<"adj list printed"<<endl;
    auto sum1 = ReturnTarget(adj, source, destination);
    int sum = sum1.first;
    if (target < sum)
        return ans;
    int diff = target - sum;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] == source && edges[i][1] == sum1.second)
        {
            edges[i][2] += diff;
        }
    }

    return edges;
}
int main()
{
    //  n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
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