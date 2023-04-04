#include <bits/stdc++.h>
using namespace std;
//  Variable size sliding window
int help(vector<int> arr, int target)
{
    int i = 0, j = 0, sum = 0, size = 0;
    while (j < arr.size())
    {
        sum += arr[j];
        if (sum == target)
        {
            size = max(size, j - i + 1);
            j++;
        }
        else if (sum < target)
        {
            j++;
        }
        else
        {
            while (sum > target)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == target)
                size = max(size, j - i + 1);
            j++;
        }
    }
    return size;
}
int main()
{
    vector<int> a{1, 1, 1, 3, 2, 5, 7};
    cout << help(a, 5);
    return 0;
}