#include <bits/stdc++.h>
using namespace std;
// METHOD 1
string invert(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    return s;
}
int i = 0;
string s;
string help(int n)
{
    if (n == 1)
        return "0";
    string p = help(n - 1);
    string g = invert(p);
    reverse(g.begin(), g.end());
    s = p + "1" + g;
    i++;
    cout << i << " " << s << endl;
    return s;
}
char findKthBit(int n, int k)
{
    string ans = help(n);
    return ans[k - 1];
}
// METHOD 1 ENDS
//METHOD 2
int form(int n,int k)
{
    if(n==1 && k==1) return 0;
    int mid = (1<<(n-1));
    if (k==mid) return 1;
    else if (k<mid) return form(n-1,k);
    else return !(form(n-1,(mid<<1)-k));
}
int main()
{
    //cout << help(6) << endl;
    cout<<(form(6,3)+'0');
    return 0;
}