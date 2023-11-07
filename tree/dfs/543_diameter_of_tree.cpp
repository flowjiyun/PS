class Solution {
public:
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode* curNode){
        if (curNode == nullptr) {
            return 0;
        }
        int left = dfs(curNode->left);
        int right = dfs(curNode->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};