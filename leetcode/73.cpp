class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstLine = false, firstCol = false;
        
        for(int i = 0; i < matrix[0].size(); i++) 
            if(matrix[0][i] == 0) firstLine = true;
        for(int j = 0; j < matrix.size(); j++)
            if(matrix[j][0] == 0) firstCol = true;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        
        if(matrix.size() > 1)
            for(int i = 1; i < matrix[1].size(); i++) 
                if(matrix[0][i] == 0)
                    for(int j = 1; j < matrix.size(); j++) matrix[j][i] = 0;
         for(int i = 1; i < matrix.size(); i++)   
            if(matrix[i][0] == 0)
                for(int j = 1; j < matrix[i].size(); j++) matrix[i][j] = 0;
        
        if(firstLine)
            for(int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
        if(firstCol)
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
};
