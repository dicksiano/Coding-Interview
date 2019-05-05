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
    int dim(TreeNode *root, int &d) {
        if(!root) return 0;
        
        int l = dim(root->left,  d);
        int r = dim(root->right, d);
        d = max(d, l + r);
        
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dim(root, d);
        return d;
    }
};
