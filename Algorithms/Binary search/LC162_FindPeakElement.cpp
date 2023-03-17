#include<bits/stdc++.h>
using namespace std;
    int findPeakElement(vector<int>& nums) {
        // BASE CASES: WHEN FIRST OR LAST ELEMENT ARE THE ANSWER
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        int lo=0,hi=nums.size()-1,n=nums.size()-1;
        if(nums[n]>nums[n-1]) return n;
        while(lo<=hi)
        {
            int mid = lo+ (hi-lo)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if (nums[mid]<nums[mid-1]) hi =mid-1; // GO TO RIGHT SIDE IF RIGHT ELEMENT IS BIGGER
            else lo = mid+1; // ELSE GO TO LEFT BEACUSE CHANCES OF FINDING THE PEAK IS MORE HERE
        /*ONE IMPORTANT ARGUMENT CAN BE THAT HOW ARE WE SURE THAT WE WILL GET A PEAK BY FOLLOWING THIS,
        WHAT IF THE PEAK IS ON THE OPPOSITE SIDE? 
        ANS-> IN THAT CASE, THERE WILL BE MULTIPLE PEAKS, THESE CONDITIONS CAN NEVER GO WRONG TRIED AND TESTED*/
        }
        return -1;
    }
int main(){
 vector<int>a{1,2,1,3,5,6,4};
 cout<<findPeakElement(a); //5
return 0;
}