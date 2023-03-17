#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
    int k=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i-1]!=nums[i])
        {
            nums[k++]=nums[i];
        }
    }
   for(int x:nums) cout<<x<<" ";
   return k;
}
int main(){
vector<int>a{0,0,1,1,1,2,2,3,3,4};
cout<< removeDuplicates(a)<<endl;
return 0;
}