#include<bits/stdc++.h>
using namespace std;
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo=1,hi = *max_element(nums.begin(),nums.end()),res=hi;
        while(lo<=hi)
        {
            int ops=0;
            int mid = lo + (hi-lo)/2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>mid)
                {
                        if(nums[i] % mid==0)
                {
                    ops+=nums[i]/mid -1 ;
                }
                else
                {
                    ops+=nums[i]/(mid);
                }
                }
            }
            if(ops<=maxOperations)
                {
                    res=mid;
                    hi=mid;
                }
                else lo=mid+1;

        }
 return res;
    }
int main(){
vector<int>a{2,4,8,2};
cout<<minimumSize(a,4);

return 0;
}