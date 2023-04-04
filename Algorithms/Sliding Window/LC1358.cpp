#include <bits/stdc++.h>
using namespace std;
/* Earlier I did it with set, and did changes in the while loop when set.size()==3 but the issue is
for strings like aaacb, output should be 3 but was coming 1. Hennce we need to maintain a array*/
int numberOfSubstrings(string s)
{
    int a = 0, b = 0, ans = 0;
    vector<int> cnt(3, 0);
    while (b < s.size())
    {
        cnt[s[b] - 'a']++;
        while (cnt[0] && cnt[1] && cnt[2])
        {
            ans += s.size() - b;
            cnt[s[a] - 'a']--;
            a++;
        }
        b++;
    }
    return ans;
}

int main()
{
    string s = "abcabc";
    cout << numberOfSubstrings(s); // 10
    return 0;
}