class Solution {
private:
    void solveNQueensRecursive(int n, int row, vector<string>& chessboard, vector<vector<string> >& result)
    {
        if (n == row)
        {
            result.push_back(chessboard);
            return;
        }
        
        for (int i = 0; i < n; ++i)
        {
            // check the column i
            int count = 0;
            for (int j = 0; j < n; ++j)
                if ('Q' == chessboard[j][i]) ++count;
            if (count >= 1) continue;
            
            // check the +1 diagonal
            count = 0;
            for (int j = 0; j < n; ++j)
            {
                int y = row+i-j;
                if (y >= 0 && y < n && 'Q' == chessboard[j][y]) ++count;
            }
            if (count >= 1) continue;
            
            // check the -1 diagonal
            count = 0;
            for (int j = 0; j < n; ++j)
            {
                int y = j + i - row;
                if (y >= 0 && y < n && 'Q' == chessboard[j][y]) ++count;
            }
            if (count >= 1) continue;
            
            // place a Queen at (row, i)
            chessboard[row][i] = 'Q';
            
            solveNQueensRecursive(n, row+1, chessboard, result);
            
            chessboard[row][i] = '.';
        }
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        
        vector<string> chessboard(n, string(n, '.'));
        solveNQueensRecursive(n, 0, chessboard, ret);
        
        return ret;
    }
};