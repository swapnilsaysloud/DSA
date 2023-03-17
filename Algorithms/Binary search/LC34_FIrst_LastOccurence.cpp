#include<bits/stdc++.h>
using namespace std;
int FindFirst(vector<int>& nums, int target)
{
int lo=0,hi=nums.size(),res=-1;
while(hi>=lo)
{
    int mid = lo + (hi-lo)/2;
    if(nums[mid]==target) 
    {
        res=mid;
        hi= mid-1;
    }
    else if (nums[mid]>target) hi = mid-1;
    else lo = mid+1;
}
return res;
}
int FindLast(vector<int>& nums, int target)
{
int lo=0,hi=nums.size(),res=-1;
while(hi>=lo)
{
    int mid = lo + (hi-lo)/2;
    if(nums[mid]==target) 
    {
        res=mid;
        lo = mid+1;
    }
    else if (nums[mid]>target) hi = mid-1;
    else lo = mid+1;
}
return res;
}
 vector<int> searchRange(vector<int>& nums, int target) {
        int first = FindFirst(nums,target);
        int last = FindLast(nums,target);
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
int main(){
vector<int>nums{2,2};
int t=3;
vector<int>a=searchRange(nums,t);
cout<<a[0]<<" "<<a[1];
return 0;
}