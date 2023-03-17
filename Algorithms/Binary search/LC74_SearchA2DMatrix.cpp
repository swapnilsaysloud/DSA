#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool BS(vector<int>arr,int x,int r,int l)
{
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid]==x) return true;
        else if(arr[mid]<x) l =mid+1;
        else { r=mid-1 ;}
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
    int l=0,r=matrix.size()-1;
    while(l<r)
    {
        int mid = l + (r-l)/2;
        if(matrix[mid].back() < target) l = mid+1;
        else if( matrix[mid][0]>target) r  = mid-1;
        else
        {
            l=mid;
            break;
        }
    }
bool ans = BS(matrix[l],target,matrix[0].size()-1,0);
    
    return ans;

    }
};