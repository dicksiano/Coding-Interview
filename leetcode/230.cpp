class Solution {
public:
    int countNodes(TreeNode *r) {
        if(r == nullptr) return 0;
        return 1 + countNodes(r->left) + countNodes(r->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int nodesLeft = countNodes(root->left);
        int nodesRight = countNodes(root->right);
        
        int pos = nodesLeft + 1;
        if(pos == k) return root->val;
        else if(k < pos) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - 1 - nodesLeft);
    }
};
