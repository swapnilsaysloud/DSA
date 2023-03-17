#include <bits/stdc++.h>
using namespace std;
int NumberMet1(vector<int> nums)
{
        /********************METHOD1**********************/
    int lo = 0, hi = nums.size() - 1, n = nums.size();
    /*
    Here’s the gist of logic used:-

    1.	To find the number of rotations in a rotated sorted array, we need to find the index of the minimum element,
    so this question gets converted to finding the index of the minimum element.
    2.	We need to mention one exceptional case here, that if the array is properly sorted (0 times rotation),
    then we can return 0 in such cases. Now, the minimum element possess a unique property here that it is less than
     both of its adjacent elements, and that is also quite obvious. So as usual we’ll check the mid element if its
      less than its previous as well as its next element. If it comes out to be like this, then it is surely the minimum element,
       and we’ll return its index. One thing we need to take care about is, suppose my mid is pointing to index=0,
       then how I’ll reach to its previous element, assuming that its previous element will be the last element
       (since it is also a rotated array), then for fetching its previous element, we need to do prev=(mid+n-1)%n,
       here mid+n-1 will give me n-1 and (n-1%n) will be n-1, which is the index of the last element. Similarly,
       if my mid is pointing to the last element, then its next element has to be the first element of the array,
        so for that do next=(mid+1)%n. By doing this, we can avoid out of bound situations.
    3.	Now, if the mid element doesn’t comes out to be the minimum element, we have to move to either side of the array,
    to pursue the binary search algorithm. We need to move to that part of the array which consists the minimum element,
     because that’s what we’re finding. Suppose my array is:- 6, 8, 9, 10, 1, 3 ,4 , then mid=3(which is pointing to 10),
      this mid is not the minimum element, so my array gets divided into two parts, one is (6,8,9,10) an the other is(10,1,2,3)
      , as you can see one part is sorted and the other one is unsorted, so my minimum element always lies in the unsorted part
      and this is true for every case. So I’ll be moving to this unsorted part of the array.
    4.	How can I decide which part is sorted and which is unsorted, then only I can proceed moving to the unsorted part in order
     to find my minimum element. For that, we need to check whether my first element is smaller than the mid element or not,
     if arr[0]<=arr[mid], then this first part of the array is sorted, and I need to do start=mid+1, in order to move to the second
     part which is unsorted. Similarly, I’ll check if arr[mid]<=arr[n-1], then the second part is sorted and first part is unsorted,
      so do end=mid-1. And then keep on doing this, you’ll definitely reach to the minimum element, because it is pretty sure that the
      minimum element lies somewhere in the array. Return mid, when the condition for the minimum element is hit.
    */
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int prev = (mid + n-1)%n; 
        int next = (mid+1)%n;     
        if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return mid;
        else if (nums[mid]>=nums[0]) lo = mid+1;
        else if( nums[mid]<=nums[n-1])
        {
            hi = mid-1;
        }

    }
    return 0;

}
int NumberMet2(vector<int> nums)
{
        /********************METHOD2**********************/
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) // not <= because we need to termonate loop when lo==hi==mid or else it will start a infinite loop
    {               // It is not searching, so there is no return statement after a point, so this is the only way to break the loop
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;
        else
        {
            hi = mid;
        }
    }
    return lo;
}
int main()
{
    vector<int> nums{4,5,6,7,0,1,2};
    cout << NumberMet1(nums);
    cout << NumberMet2(nums);
    return 0;
}