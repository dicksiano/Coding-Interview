class Solution {
public:
    TreeNode* build(int x, int s, int e, vector<int>& preorder, vector<int>& inorder) {
        if(x > preorder.size()-1 || s > e) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[x]);
        int pos;
        for(int i = s; i <= e; i++)
            if(preorder[x] == inorder[i]) pos = i;
        
        root->left = build(x+1, s, pos-1, preorder, inorder);
        root->right = build(x + pos - s + 1, pos+1, e, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, preorder.size()-1, preorder, inorder);
    }
};
