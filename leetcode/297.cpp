
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "n";
        return to_string(root->val) + "|" + serialize(root->left) + "|" + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* d(string &s) {
        if(s[0] == 'n') {
            if(s.size() > 1) s = &s[2];
            return nullptr;
        }
         
        int nextMarker = s.find('|');
        int val = stoi( s.substr(0, nextMarker) );
            
        s = &s[nextMarker + 1];
        TreeNode *head = new TreeNode(val);
        head->left = d(s);
        head->right = d(s);
        
        return head;
    }
    
    TreeNode* deserialize(string data) {
        return d(data);
    }
};
