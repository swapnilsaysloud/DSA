#include <bits/stdc++.h>
using namespace std;
bool isNice(string s)
{
    set<char> st;
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    auto it = st.begin();
    while (it != st.end())
    {
        char x = *it;
        char y = x + 32;
        if (st.find(y) != st.end())
        {
            st.erase(y);
            it++;
        }
        else
            return false;
    }
    return true;
}
string longestNiceSubstringBruteForce(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= s.size() - i; j++)
        {
            string temp = s.substr(i, j);
            if (isNice(temp) && temp.size() > ans.size())
            {
                ans = temp;
            }
        }
    }
    return ans;
}
/*
Difference between recursion and divide/ Conquer:
Recursion is one way of solving problems using divide and conquer
divide and conquer involves breaking problem into smaller parts and 
solving them independently and merging them to get final answer.
recurion is solving bigger problems using smaller ones.
*/
string longestNiceSubstringDivideConquer(string s)
{
    // Base case, will return null values if s is if 1 char
    if (s.size() < 2)
        return "";
    set<char> st(begin(s), end(s));
    for (int i = 0; i < s.size(); i++)
    {
        // We find the char for which upper or lower case is not present. From there we break 
        // string into two.
        if (st.find(tolower(s[i])) == st.end() || st.find(toupper(s[i])) == st.end())
        {
            string s1 = longestNiceSubstringDivideConquer(s.substr(0, i));
            string s2 = longestNiceSubstringDivideConquer(s.substr(i + 1));
            return s1.size() >= s2.size() ? s1 : s2;
        }
    }
    return s;
}
int main()
{
   string s = "YazaAay";
   cout<<longestNiceSubstringDivideConquer(s)<<endl;
   cout<<longestNiceSubstringBruteForce(s)<<endl;
    return 0;
}