class Trie {
public:
    Trie() {
        for(int i = 0; i < 26; i++) child[i] = nullptr;
        word = "";
    }
    Trie *child[26];
    string word;
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, Trie *p, int i, int j, vector<string> &res) {
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board[0].size()) return;
                
        char aux = board[i][j];
        if(aux == '0' || p->child[aux - 'a'] == nullptr) return;
        p = p->child[aux - 'a'];
        
        if(p->word.size() > 0) { res.push_back(p->word); p->word = ""; }
        
        board[i][j] = '0';        
        dfs(board, p, i-1, j, res);
        dfs(board, p, i+1, j, res);
        dfs(board, p, i, j-1, res);
        dfs(board, p, i, j+1, res);        
        board[i][j] = aux;        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = build(words);
        vector<string> res;
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                dfs(board, root, i, j, res);
        return res;
    }
    
    Trie* build(vector<string> w) {
        Trie *p, *root = new Trie();
        for(int i = 0; i < w.size(); i++) {
            p = root;            
            for(int j = 0; j < w[i].size(); j++) {
                int ind = w[i][j] - 'a';
                if(p->child[ ind ] == nullptr) p->child[ ind ] = new Trie();
                p = p->child[ ind ];
            }
            p->word = w[i];
        }
        return root;
    }
};
