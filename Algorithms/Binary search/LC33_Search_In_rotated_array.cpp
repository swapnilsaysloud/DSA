    #include<bits/stdc++.h>
    using namespace std;
    int search(vector<int>& nums, int target) {
       int lo =0,hi=nums.size() -1;
       // Finding index of the least element
       while(lo<hi)
       {
           int mid = lo + (hi-lo)/2;
           if(nums[mid]>nums[hi]) lo=mid+1;
           else
           {
               hi = mid;
           }
       }
       int rot = lo;  // lo-> index of least element
       cout<<rot;
       hi = nums.size()-1;
       lo = 0;
       // applying binary search in the modified vector. after considering the original vector but 
       // with indices of rotated array
       while(lo<=hi)
       {
           int mid = lo + (hi-lo)/2;
           int realMid = (mid+rot)%nums.size(); // % to keep it in range
           if(nums[realMid]==target) return realMid;
           else if(nums[realMid]>target) hi = mid-1;
           else {
               lo = mid+1;
           }
       }
       return -1;

    }
    int main(){
     vector<int> vect{ 4,5,6,7,0,1,2 };
     int t = 3;
     int ans= search(vect,t);
     cout<<ans;
    return 0;
    }