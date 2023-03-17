#include<bits/stdc++.h>
using namespace std;
 int mySqrt(int x) {
   int lo=0,hi=x-1;
   // BINARY SEARCH BEACUSE WE CAN USE THE SORTED PROPERTY OF INTEGERS
   while(lo<=hi)
   {
      long long int mid = lo+(hi-lo)/2; // TO CONTROL INTEGER OVERFLOW IN THE NEXT LINE
       if((mid+1)*(mid+1)==x) return mid+1;
       else if((mid+1)*(mid+1)>x) hi=mid-1;
       else lo = mid+1;
   }
   return hi+1;
    }
int main(){
cout<<mySqrt(9)<<endl;
cout<<mySqrt(8);
return 0;
}