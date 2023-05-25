#include <bits/stdc++.h>
using namespace std;
/* KADANE's Algorithm */
int maxSubArray(const vector<int> &A)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < A.size(); i++)
    {
        max_ending_here += A[i];
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
// TLE in this solution
int help(vector<int>a,int n)
{
    if(n==0) return 0;
    return max((a[n-1]+help(a,n-1)),help(a,n-1));
}
int main()
{
    vector<int> a{1, 2, 3, 4, -10};
    //cout << maxSubArray(a);
    cout<<help(a,a.size());
    return 0;
}