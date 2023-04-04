#include <bits/stdc++.h>
using namespace std;
// Recursive solution
int helpRecur(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n == 0)
        return 0;
    return helpRecur(arr, n, sum - arr[n - 1]) + helpRecur(arr, n - 1, sum);
}
int helpMemo(vector<int> &a, int sum, int n,
             vector<vector<int>> &dp)
{
    
}
int main()
{
    int i, j;
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;

    cout <<  helpRecur(coins, n, sum)<<endl;
    vector<int> a = {1, 2, 3};
    vector<vector<int>> dp(n + 1,
                           vector<int>(sum + 1, -1));
    
    cout<< helpMemo(a,sum,n,dp)<<endl;

    return 0;
}