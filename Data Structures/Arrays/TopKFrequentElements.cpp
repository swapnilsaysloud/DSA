
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto x : nums)
        mp[x]++;
    priority_queue<pair<int, int>> pq;
    for (auto x : mp)
        pq.push({x.second, x.first});
    while (k--)
    {
        auto p = pq.top();
        ans.push_back(p.second);
        pq.pop();
    }
    return ans;
}
int main()
{

    return 0;
}