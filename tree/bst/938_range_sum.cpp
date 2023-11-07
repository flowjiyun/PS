class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        m_low = low;
        m_high = high;
        dfs(root);
        return m_sum;
    }
    void dfs(TreeNode* curNode) {
        if (curNode == nullptr) {
            return ;
        }
        if (curNode->val >= m_low && curNode->val <= m_high) {
            m_sum += curNode->val;
        }
        if (curNode->val >= m_low) {
            dfs(curNode->left);
        }
        if (curNode->val < m_high) {
            dfs(curNode->right);
        }
    }

private:
    int m_low;
    int m_high;
    int m_sum {0};
};