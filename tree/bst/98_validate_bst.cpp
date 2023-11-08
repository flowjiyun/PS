class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long low = numeric_limits<long long>::min();
        long long high = numeric_limits<long long>::max();

        return dfs(root, low, high); 
    }

    bool dfs(TreeNode* curNode, long long low, long long high) {
        if (curNode == nullptr) {
            return true;
        }
        if (curNode->val <= low || curNode->val >= high) {
            return false;
        }

        bool left = dfs(curNode->left, low, curNode->val);
        bool right = dfs(curNode->right, curNode->val, high);
        return left && right;
    }
};