bool used(vector<vector<char>>& board, int row[][9], int col[][9], int subg[][9], int i, int j) {
  int val = board[i][j] - '1';
  int grid = (i/3) * 3 + j/3;
        
  bool isRowUsed  = row[i][val];
  bool isColUsed  = col[j][val];
  bool isGridUsed = subg[grid][val];
        
  if(isRowUsed || isColUsed || isGridUsed) return true;
        
  row[i][val] = col[j][val] = subg[grid][val] = true;
  return false;
}
    
bool isValidSudoku(vector<vector<char>>& board) {
  int row[9][9] = {0}, col[9][9] = {0}, subg[9][9] = {0};
        
  for(int i = 0; i < board.size(); i++)
    for(int j = 0; j < board[0].size(); j++)
      if(board[i][j] != '.' && used(board, row, col, subg, i, j)) 
        return false;
  return true;
}
