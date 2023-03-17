#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>arr;
    cout<<"Input now"<<endl;;
    for(int i=0;i<4;i++)
    {
        for (size_t p = 0; p < 4; p++)
        {
            cin>> arr[i][p];
        }
        
    }
    for( vector<int> x :arr )
    {
        for( auto put :x)
        {
            cout<<put<<" ";
        }
        cout<<endl;
    }
}
