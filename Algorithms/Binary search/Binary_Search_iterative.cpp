#include <bits/stdc++.h>
using namespace std;
// TC: O(LOGN)
//SC: O(1)
/* BASIC CONCEPT: FIND MID ELEMENT AUR FIND CONDITIONS KI MID SE RIGHT JAANA H YA LEFT */
int BS(int arr[],int x,int r,int l)
{
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) l =mid+1;
        else { r=mid-1 ;}
    }
    return -1;
}
int main() {
    int arr[]={1,2,4,6,5,9,75,455};
    int ans=BS(arr,900,7,0);
    cout<<ans;
    return 0;
}