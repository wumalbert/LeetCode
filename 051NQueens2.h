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
 
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nSolution = 0;
        vector<string> chessboard(n, string(n, '.'));
        solveNQueensRecursive(n, 0, chessboard, nSolution);
        
        return nSolution;
    }
};
class Solution {
public:
    int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count = 0;
        dfs((1<<n)-1, 0, 0, 0, count);
        return count;
    }
	
private:
    void dfs(int upper, int column, int left, int right, int &count) {
        if (column == upper) {
            ++count;
            return;
        }
        int row = upper & ~(column | left | right);
        while (row) {
            int p = row & (~row+1);
            row ^= p;
            dfs(upper, column|p, (left|p) << 1, (right|p) >> 1, count);
        }
    }
};