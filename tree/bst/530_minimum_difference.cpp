class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> list;
        dfs(root, list);
        int ans = numeric_limits<int>::max();
        for (size_t i = 1; i < list.size(); ++i) {
            ans = min(ans, list[i] - list[i - 1]);
        }
        return ans;
    }

    void dfs(TreeNode* curNode, vector<int>& list) {
        if (curNode == nullptr) {
            return;
        }
        dfs(curNode->left, list);
        list.push_back(curNode->val);
        dfs(curNode->right, list);
    }
};