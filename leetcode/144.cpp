/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> sol;

        if(root) s.push(root);
        while(!s.empty()) {
            TreeNode *tmp = s.top(); s.pop();
            sol.push_back(tmp->val);
            if(tmp->right != nullptr) s.push(tmp->right);
            if(tmp->left  != nullptr) s.push(tmp->left);
        }
        return sol;
    }
};
