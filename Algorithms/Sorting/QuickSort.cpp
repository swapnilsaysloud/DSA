// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
// With pivot as the first element
int partition(int l, int h,int arr[])
{
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
   i++;
    int temp=arr[i];
            arr[i]=arr[h];
            arr[h]=temp;
   return i; // Pivot index
}
void Quicksort(int l,int h,int arr[])
{
    if(l<h)
    {
        int j=partition(l,h,arr);
        Quicksort(l,j-1,arr);
        Quicksort(j+1,h,arr);
    }
}
int main() {
  int arr[]={2,45,3,45,6,7,54,26};
  int h=(sizeof(arr)/4)-1;
  Quicksort(0,h,arr);
  for(int i=0;i<=h;i++)
  {
      cout<<arr[i]<<" ";
  }
    return 0;
}