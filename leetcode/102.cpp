class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> sol;
        if(root == nullptr) return sol;
        
        queue<TreeNode*> q[2];
        q[0].push(root);
        
        while(!q[0].empty() || !q[1].empty()) {
            for(int i = 0; i < 2; i++) {
                vector<int> aux;
                int other = (i+1) % 2;
                while(!q[i].empty()) {
                    TreeNode* p = q[i].front(); q[i].pop();
                    if(p->left) q[other].push(p->left);
                    if(p->right) q[other].push(p->right);

                    aux.push_back(p->val);
                }
                if((int)aux.size()) sol.push_back(aux);
            }            
        }
        return sol;
    }
};
