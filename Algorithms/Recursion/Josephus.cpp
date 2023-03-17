#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> v, int index, int k, int ans)
{
    //Base condition
    if (v.size() == 1)
    {
        ans = v[0];
        return ans;
    }
    // Circular linked list can also be used 
    // By Using % we took the index again to starting 
    index = (index + k) % v.size();
    // Removing the element
    v.erase(v.begin() + index);
    return (solve(v, index, k, ans));
}
int main()
{
    int n, k, ans;
    //n= number of people
    // k= counting ends at k from 1
    vector<int> v;
    cout << "Input n: " << endl;
    cin >> n;
    cout << "Input k: " << endl;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    k--;//Because counting started from 1 by the person
    cout << "Last man standing is at " << solve(v, 0, k, 0) << endl;
}