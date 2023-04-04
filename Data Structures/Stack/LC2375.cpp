#include<bits/stdc++.h>
using namespace std;
string smallestNumber(string pattern) 
{
    stack<int>s;
    string ans;
    for(int i=0;i<=pattern.size();i++)
    {
     s.push(i+1);
     if(pattern[i]=='I' || i==pattern.size())
     {
        while(!s.empty())
        {
          ans+= to_string(s.top());
          s.pop();
        }
     }
    }
    return ans;
}
// WRONG SOLUTION (MINE)
/*
    string smallestNumber(string pattern) {
        int ans=1;
        string s;
        stack<char>st;
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='I' && st.empty() ) s+=to_string(ans++) ;
             if (pattern[i]=='D') st.push('D');
             if ((pattern[i]=='I' && !st.empty()) || (!st.empty() && i==pattern.size()-1))
            {
                int temp = st.size();
                ans+= st.size() ;
                
                while(!st.empty())
                {
                 s += to_string(ans--);
                 st.pop();
                }
                s += to_string(ans++);
            }
        }
        return s;
    }
*/
int main(){

return 0;
}