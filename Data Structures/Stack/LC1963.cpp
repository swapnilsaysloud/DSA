#include<bits/stdc++.h>
using namespace std;
// SOLUTION WITH STACK
  /* int minSwaps(string s) {
        stack<char>st;
        int mismatch=0;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(c == '[') st.push(c);
            else if ( c==']' && !st.empty()) st.pop();
            else mismatch ++;
        }
        int ans = (mismatch+1)/2;
        return ans;
    } */
    // SOLUTION WITHOUT STACK
    int minSwaps(string s) {
        int st=0;
        int mismatch=0;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(c == '[') st++;
            else if ( c==']' && st!=0) st--;
            else mismatch ++;
        }
        int ans = (mismatch+1)/2;
        return ans;
    }
int main(){

return 0;
}