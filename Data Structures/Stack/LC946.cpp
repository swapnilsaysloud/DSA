#include <bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0, j = 0;
  for(int x: pushed)
  {
    st.push(x);
    while(!st.empty() && st.top()==popped[j])
    {
        st.pop();
        j++;
    }
  }
    if(!st.size()) return true;
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return false;
}
int main()
{
vector<int>pushed{1,2,3,4,5};
vector<int>popped{4,5,3,2,1};
cout<<validateStackSequences(pushed,popped);

    return 0;
}