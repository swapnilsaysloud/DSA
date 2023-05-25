#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = map.find(target - nums[i]);
        // Number found in map.first list
        if (it != map.end()) // Successful search
            return vector<int>{i, it->second};
        // Number not found, then store in map for future numbers
        map[nums[i]] = i;
    }
    return ans;
}
int main()
{

    return 0;
}
