#include <bits/stdc++.h>
using namespace std;
// WRONG SOLUTION
int help(vector<int> vec, int k, int size)
{
    int ret = 0;
    long long int ans = 1;
    for (int i = 0; i < size; i++)
        ans *= vec[i];
    if (ans < k)
        ret++;
    for (int i = size; i < vec.size(); i++)
    {
        ans = (ans * vec[i]); // REASON: overflow at this point
        ans /= vec[i - size];
        if (ans < k)
            ret++;
    }
    return ret;
}
int numSubarrayProductLessThanKWRONG(vector<int> &nums, int k)
{
    int ans = 0;
    for (int i = 1; i <= nums.size(); i++)
        ans += help(nums, k, i);
    return ans;
}
// CORRECT SOLUTION
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int lo = 0, ans = 0, pdt = 1;
    if (k <= 1)
        return 0;
    for (int hi = 0; hi < nums.size(); hi++)
    {
        pdt *= nums[hi];
        while (pdt >= k)
            pdt /= nums[lo++];
        ans += hi - lo + 1; //  ADDING WINDOW SIZE BECAUSE WE WANT TO INCLUDE ARRAY OF ALL SIZES
    }
    return ans;
}
int main()
{

    return 0;
}