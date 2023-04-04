#include <bits/stdc++.h>
using namespace std;
// Catalan number: 2n!/(n+1)!n! OR sigma(Ci * Cn-i)
// Recursive Solution
long long int CatRecur(int n)
{
    if (n <= 1)
        return 1;
    long long int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += CatRecur(i) * CatRecur(n - 1 - i);
    }
    return res;
}
// Memoization Answer
long long int Catmemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    long long int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += Catmemo(i, dp) * Catmemo(n - 1 - i, dp);
    }
    dp[n] = res;
    return dp[n];
}

int main()
{
    int n = 10;
    cout << CatRecur(n) << " ";
    vector<int> dp(n + 1, -1);
    cout << Catmemo(n, dp);

    return 0;
}