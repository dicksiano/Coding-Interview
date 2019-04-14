class Solution {
public:
    bool check(TreeNode* root, TreeNode* mini, TreeNode* maxi) {
        if(root == nullptr) return true;        
        if(mini && root->val <= mini->val) return false;
        if(maxi && root->val >= maxi->val) return false;
        return check(root->left, mini, root) && check(root->right, root, maxi);
    }
    
    bool isValidBST(TreeNode* root) {   
        return check(root, nullptr, nullptr); 
    }
};
