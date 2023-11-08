class Solution {
public:
    vector<int> list;
    int closestValue(TreeNode* root, double target) {
        dfs(root);
        int closest = list[0];
        double prevDiff = abs(closest - target);
        for (int i = 1; i < list.size(); ++i) {
            double curDiff = abs(list[i] - target);
            if (curDiff < prevDiff) {
               prevDiff = curDiff; 
               closest = list[i];
            }
        }
        return closest;
    }

    void dfs(TreeNode* curNode) {
        if (curNode == nullptr) {
            return;
        }
        dfs(curNode->left);
        list.push_back(curNode->val);
        dfs(curNode->right);
    }
};