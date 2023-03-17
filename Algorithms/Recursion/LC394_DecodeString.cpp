#include <bits/stdc++.h>
using namespace std;
// 2[abc]3[cd]ef
string ans;
string help(string &s, int &i)
{
    string temp;
    while (i < s.length() && s[i] != ']')
    {
        if (!isdigit(s[i]))
        {
            temp += s[i++];
        }
        else
        {
            int n = 0;
            while (i < s.length() && isdigit(s[i]))
                n = n * 10 + s[i++] - '0';

            i++;
            string t = help(s, i);
            i++;
            while (n-- > 0)
                temp += t;
        }
    }
    return temp;
}
string decodeString(string s)
{
    int i=0;
    return help(s, i);
}
int main()
{
    cout<<decodeString("2[abc]3[cd]ef");
    return 0;
}