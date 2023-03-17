/*Given an array of integers arr[], The task is to 
find the index of first repeating element in it i.e.
 the element that occurs more than once and whose index 
 of the first occurrence is the smallest. */
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 int arr[] = {10, 5, 3, 4, 3, 5, 6};
 unordered_map<int,int>mp;
 for(int x:arr)    mp[x]++;
 for(int x:arr) 
 if(mp[x]==2)
 {
    cout<<x;
    break;
 }

 return 0;
 }