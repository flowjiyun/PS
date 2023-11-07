class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int curMaxVal = 0;
        int curMinVal = numeric_limits<int>::max();
        return dfs(root, curMaxVal, curMinVal);
    }

    int dfs(TreeNode* curNode, int curMaxVal, int curMinVal) {
        if (curNode == nullptr) {
            return abs(curMaxVal - curMinVal);
        }

        curMaxVal = max(curMaxVal, curNode->val);
        curMinVal = min(curMinVal, curNode->val);

        int left = dfs(curNode->left, curMaxVal, curMinVal);
        int right = dfs(curNode->right, curMaxVal, curMinVal);
        return max(left, right);
    }
};