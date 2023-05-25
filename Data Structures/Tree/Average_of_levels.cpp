#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
Related to level order traversal
The for loop manages each level individually
*/
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double>ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int num = q.size(); // Number of nodes in  level
        double avg = 0;
        for (int i = 0; i < num; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr)
            {
                avg += (double)curr->val;
                if(curr->right) // This check is important as else null is pushed in queue and it unnesserily increases size of queue
                q.push(curr->right);
                if(curr->left)
                q.push(curr->left);
            }
        }
        avg /= num;
        ans.push_back(avg);
    }
    return ans;
}
int main()
{

    return 0;
}