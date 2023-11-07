class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       if (root == nullptr) {
           return vector<int>{};
       }

       vector<int> ans;
       queue<TreeNode*> list;
       list.push(root);

       while (!list.empty()) {
           int length = list.size();
           int maxVal = numeric_limits<int>::min();
           for (int i = 0; i < length; ++i) {
               TreeNode* curNode = list.front();
               list.pop();

               maxVal = max(maxVal, curNode->val);
               if (curNode->left) {
                   list.push(curNode->left);
               }
               if (curNode->right) {
                   list.push(curNode->right);
               }
           }
           ans.push_back(maxVal);
       }
       return ans;
    }
};