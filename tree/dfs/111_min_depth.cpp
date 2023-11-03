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
    int minDepth(TreeNode* root) {
        return dfs(root); 
    }
    int dfs(TreeNode* curNode) {
        if (curNode == nullptr) {
            return 0;
        } 
        if (curNode->left == nullptr && curNode->right) {
            return 1 + dfs(curNode->right);
        }
        if (curNode->right == nullptr && curNode->left) {
            return 1 + dfs(curNode->left);
        }
        int left = dfs(curNode->left);
        int right = dfs(curNode->right);
        return min(left, right) + 1;
    }
};