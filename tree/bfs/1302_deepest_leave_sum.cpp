class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> list;
        int lastSum;
        list.push(root);

        while (!list.empty()) {
            int length = list.size();
            int sum = 0;
            for (int i = 0; i < length; ++i) {
                TreeNode* curNode = list.front();
                list.pop();

                sum += curNode->val;
                if (curNode->left) {
                    list.push(curNode->left);
                }
                if (curNode->right) {
                    list.push(curNode->right);
                }
            }
            lastSum = sum;
        } 
        return lastSum;
    }
};