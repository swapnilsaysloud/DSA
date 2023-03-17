#include <bits/stdc++.h>
using namespace std;
// Recursive solution
vector<int> diffWaysToComputeRecursion(string expression)
{
    vector<int> result;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*')
        {
            // dividing original string into 2 strings
            vector<int> result1 = diffWaysToComputeRecursion(expression.substr(0, i)); // computing combinations from both the string
            vector<int> result2 = diffWaysToComputeRecursion(expression.substr(i + 1, expression.size() - i - 1));

            for (auto x : result1)
            {
                for (auto y : result2)
                {
                    if (c == '+')
                        result.push_back(x + y);
                    if (c == '-')
                        result.push_back(x - y);
                    if (c == '*')
                        result.push_back(x * y);
                }
            }
        }
    }
    if (result.empty()) // if original string consisted of only numbers
    {
        result.push_back(atoi(expression.c_str()));
    }
    return result;
}
    unordered_map<string,vector<int>>dp;
vector<int> diffWaysToComputeDP(string expression) {
    vector<int> result;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*')
        {
            vector<int> result1 ;
            string first = expression.substr(0, i);
            if(dp.find(first) != dp.end())  result1=dp[first];
            else    result1 = diffWaysToComputeDP(first);


            vector<int> result2;
            string second = expression.substr(i + 1, expression.size() - i - 1);
            if(dp.find(second) != dp.end()) result2 = dp[second];
            else result2 = diffWaysToComputeDP(second);


            for (auto x : result1)
            {
                for (auto y : result2)
                {
                    if (c == '+')
                        result.push_back(x + y);
                    if (c == '-')
                        result.push_back(x - y);
                    if (c == '*')
                        result.push_back(x * y);
                }
            }
        }
    }
    		if (result.empty())
			result.push_back(atoi(expression.c_str()));
		dp[expression] = result;
		return result;

    }
int main()
{
string s = "2*3-4*5";
vector<int>v = diffWaysToComputeRecursion(s);
vector<int>w = diffWaysToComputeDP(s);
for(int x:v) cout<<x<<" ";
cout<<endl;
for(int x:w) cout<<x<<" ";
    return 0;
}