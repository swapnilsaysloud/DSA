#include <bits/stdc++.h>
using namespace std;

int OnlyOne(vector<int> nums)
{
    int x = 0, ans = 0;
    for (auto y : nums)
    {
        if (y != 0)
        {
            x++;
            ans = y;
        }
    }
    if (x == 1)
        return ans;
    return 0;
}
int help(vector<int> &nums, int start, int end, int skip, int direction)
{
    int ans1,ans2;
    if (OnlyOne(nums) != 0)
    {
        return OnlyOne(nums);
    }
    if (direction == 1)
    {
        int i = start;
        while (i <= end)
        {
            nums[i] = 0;
            i += skip;
        }
        ans1= help(nums, start, end - 1, skip + 2, direction * (-1));
    }
    if (direction == -1)
    {
        int i = end;
        while (i >= start)
        {
            nums[i] = 0;
            i -= skip;
        }
         ans2 = help(nums, start + 1, end, skip + 2, direction * (-1));
    }
    if(ans1 != 0) return ans1;
    if(ans2 !=0) return ans2;

    return 0;
}
int lastRemaining(int n)
{
    vector<int> a;
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    int ans = help(a, 0, n - 1, 2, 1);
    return ans;
}
int main()
{
    cout << lastRemaining(15);
    return 0;
}