#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
string s;
cin>>s;
if(n==1)
{
cout<<"Yes"<<endl;
  return 0;
}
bool flag = false;
for(int i=0;i<n-1;i++)
{
    if(s[i]=='M' && s[i+1] !='F') 
    {
        cout<<"No"<<endl;
        flag = true;
        break;
    }
        if(s[i]=='F' && s[i+1] !='M') 
    {
        cout<<"No"<<endl;
        flag = true;
        break;
    }
}
if (flag==false) cout<<"Yes"<<endl;

return 0;
}