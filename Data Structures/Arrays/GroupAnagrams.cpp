
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> s;
    unordered_map<string, vector<string>> a;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        a[s].push_back(strs[i]);
    }
    for (auto x : a)
    {
        s.push_back(x.second);
    }
    return s;
}
int main()
{

    return 0;
}