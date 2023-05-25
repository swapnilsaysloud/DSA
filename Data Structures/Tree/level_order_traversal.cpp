#include <bits/stdc++.h>
using namespace std;
/*
IMPORTANT CONCEPT!!!
 Variations:
 ZigZag traversal: reverse every other vector of currentlevel
 BottomUp traversal: reverse the final vector is the best approach
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;

    if (root == nullptr)
        return levels;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = nodeQueue.front();
            nodeQueue.pop();

            currentLevel.push_back(current->val);

            if (current->left != nullptr)
                nodeQueue.push(current->left);

            if (current->right != nullptr)
                nodeQueue.push(current->right);
        }

        levels.push_back(currentLevel);
    }

    return levels;
}
int main()
{

    return 0;
}