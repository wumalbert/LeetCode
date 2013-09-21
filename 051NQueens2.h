class Solution {
private:
    void solveNQueensRecursive(int n, int row, vector<string>& chessboard, int& nSolution)
    {
        if (n == row)
        {
            ++nSolution;
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
            
            solveNQueensRecursive(n, row+1, chessboard, nSolution);
            
            chessboard[row][i] = '.';
        }
    }
    
    void queens(int upper, int col, int ld, int rd, int& count)
    {
        if (col == upper)
        {
            ++count;
            return;
        }
        
        int row = upper & ~(col | ld | rd);
        
        while (row)
        {
            int p = row & (~row+1);
            row ^= p;
            
            queens(upper, col|p, (ld|p) << 1, (rd|p) >> 1, count);
        }
    }
    
public:
    int totalNQueens01(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nSolution = 0;
        vector<string> chessboard(n, string(n, '.'));
        solveNQueensRecursive(n, 0, chessboard, nSolution);
        
        return nSolution;
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0;
        int upper = (1 << n) - 1;
        
        queens(upper, 0, 0, 0, count);
        
        return count;
    }
};