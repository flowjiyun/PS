/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum;
    int goodNodes(TreeNode* root) {
        sum = 0;
        dfs(root, root->val);
       return sum;
    }
    void dfs(TreeNode* curNode, int curMaxVal) {
        if (curNode == nullptr) {
            return ;
        }
        if (curNode->val >= curMaxVal) {
            ++sum;
        }
        curMaxVal = max(curMaxVal, curNode->val);
        dfs(curNode->left, curMaxVal);
        dfs(curNode->right, curMaxVal);
    }
};