class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }

        vector<int> ans;
        queue<TreeNode*> list;
        list.push(root);
        while (!list.empty()) {
            int length = list.size();
            ans.push_back(list.back()->val);
            for (int i = 0; i < length; ++i) {
                TreeNode* curNode = list.front();
                list.pop();

                if (curNode->left) {
                    list.push(curNode->left);
                }
                if (curNode->right) {
                    list.push(curNode->right);
                }
            }
        }
        return ans; 
    }
};