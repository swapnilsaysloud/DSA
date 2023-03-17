#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> g[N];       // adj list for unweighted graph
vector<vector<int>> cc; // for storing connected components
vector<int> current_cc; // storing individual connected component
void dfs(int vertex)
{

    // cout<<vertex<<endl;
    vis[vertex] = true; // marking thus node as visited
    current_cc.push_back(vertex);
    for (auto child : g[vertex])
    {
        if (vis[child])
            continue;
        //  cout<<"par "<< vertex <<" child "<<child<<endl;
        dfs(child);
    }
}

int main()
{
    int n, e;
    cout << "Enter n and e" << endl;
    cin >> n >> e;
    // taking input of graph
    cout << " Start entering edges " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // undirected
        g[v].push_back(u);
    }
    // jab kisi vertex pe dfs call hoga toh vo uske saare connected components ko visited mark kar dega, toh baakiyon pe dfs alag se call hoga
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        count++;
    }
    cout << "No. of strongly connected components: " << count << endl;
    for (auto c_cc : cc)
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
    return 0;
}