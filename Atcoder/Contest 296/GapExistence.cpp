#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x;
cin>>x;
set<int>s;
s.insert(0);
for(int i=0;i<n;i++)
{
    int p;
    cin>>p;
    s.insert(p);
}
bool flag = true;
for(auto it = s.begin();it!=s.end();it++)
{
    if(s.find(*it+x) != s.end())
    {
        cout<<"Yes";
        return 0;
        flag = false;
    }
}
if(flag) cout<<"No";
return 0;
}