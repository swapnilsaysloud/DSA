#include <bits/stdc++.h>
using namespace std;
void insert(vector<int>&v,int val)
{
    if( v.size()==0 || v[v.size()-1]<=val)
    {
        v.push_back(val);
        return ;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    insert(v,val);
    v.push_back(temp);
}
void sort(vector<int>&v)
{
    if (v.size()==1)
    {
        return ;
    }
    int val = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,val);
}

int main() {
  vector<int>v={1,4,2,8,5,6,9};
  sort(v);
  for(auto it:v)
   cout<<it<<" ";
    return 0;
}