class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || j >= board[0].size()) return false;
        
        if(word[0] != board[i][j]) return false;
        else if(word.size() == 1 ) return true;
        
        bool res = false;
        char aux = board[i][j];
        board[i][j] = '0';
        
        res |= dfs(board, &word[1], i-1, j);
        if(!res) res |= dfs(board, &word[1], i+1, j);
        if(!res) res |= dfs(board, &word[1], i, j-1);
        if(!res) res |= dfs(board, &word[1], i, j+1);
        
        board[i][j] = aux;
        return res;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(word[0] == board[i][j] && dfs(board, word, i , j)) return true;
        return false;
    }
};
