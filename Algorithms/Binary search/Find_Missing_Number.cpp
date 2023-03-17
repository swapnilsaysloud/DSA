/*Given an array arr[] of size N-1 with integers in 
the range of [1, N], the task is to find the missing 
number from the first N integers*/
#include<bits/stdc++.h>
using namespace std;
int main(){
/*
TC:O(N)
SC:O(N)
int arr[]={1,2,3,4,6,7,8};
unordered_map<int,int>mp;
for(int x:arr) mp[x]++;
for(int i=1;i<=8;i++)
{
    if(mp[i]!=1) cout<<i;
}*/

int arr[]={1,2,3,4,6,7,8};
int n=8;
int sum =0,exp_sum;
exp_sum=n*(n+1)/2;
for(int x:arr)sum+=x;
int ans=exp_sum-sum;
cout<<ans;
//TC:O(N)
//SC:O(N)
return 0;
}