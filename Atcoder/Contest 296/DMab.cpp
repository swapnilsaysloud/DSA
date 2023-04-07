#include<bits/stdc++.h>
using namespace std;
int main(){
    // TLE in this code
    /*
long long int n,m;
cin>>n;
cin>>m;
int big = n;
if(pow(big,2) < m) 
{
    cout<<"-1";
    return 0;
}
long long int x = m-1;
while(x++)
{
    for(int i=1;i<=n;i++)
    {
        if((x % i == 0) && (x/i)<=n )
        {
            cout<<x;
            return 0;
        }
    }
}*/
long long int n,m;
cin>>n;
cin>>m;
for(int i=1;i<n;i++)
{
    int j = (m+i-1)/i;
    if(i>j) break;
    if ( j<=n) 
    {
        cout<<i*j;
        break;
    }
}
return 0;
}