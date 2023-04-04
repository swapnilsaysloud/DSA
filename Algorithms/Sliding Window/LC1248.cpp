// Nummber of nice subarrays
#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int j = 0, odd = 0, count = 0, result = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1)
        {
            odd++;
            if (odd >= k)
            {
                count = 1;
                while (nums[j++] % 2 == 0)
                {
                    count++;
                    // j++;
                }
                result += count;
            }
        }
        else if (odd >= k)
            result += count;
    }
    return result;
}

int main()
{
    vector<int> nums{1, 1, 2, 1, 1};
    cout << numberOfSubarrays(nums, 3);
    return 0;
}
