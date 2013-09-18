class Solution {
private:
    static const int kSize = 9;

    bool solveSudokuRecursive(vector<vector<char> > &board, int n, 
        vector<vector<bool> >& rowFlags,
        vector<vector<bool> >& columnFlags,
        vector<vector<bool> >& blockFlags
        ) {
            int i = n / kSize;
            int j = n % kSize;

            if ('.' == board[i][j])
            {
                // find the candidate value
                for (int k = 0; k < kSize; ++k)
                {
                    if(rowFlags[i][k] || columnFlags[j][k] || blockFlags[(i/3)*3 + j/3][k])
                        continue;

                    board[i][j] = k + '1';
                    rowFlags[i][k] = true;
                    columnFlags[j][k] = true;
                    blockFlags[(i/3)*3 + j/3][k] = true;

                    if (n == kSize*kSize-1) return true;

                    if (solveSudokuRecursive(board, n+1, rowFlags, columnFlags, blockFlags))
                        return true;

                    board[i][j] = '.';
                    rowFlags[i][k] = false;
                    columnFlags[j][k] = false;
                    blockFlags[(i/3)*3 + j/3][k] = false;
                }
            }
            else
            {
                if (n == kSize*kSize-1) return true;

                if (solveSudokuRecursive(board, n+1, rowFlags, columnFlags, blockFlags))
                    return true;
            }
            return false;
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > rowFlags(kSize, vector<bool>(kSize, false));
        vector<vector<bool> > columnFlags(kSize, vector<bool>(kSize, false));
        vector<vector<bool> > blockFlags(kSize, vector<bool>(kSize, false));

        // set the initial flags
        for (int i = 0; i < kSize; ++i)
        {
            for (int j = 0; j < kSize; ++j)
            {
                if ('.' == board[i][j]) continue;
                int t = board[i][j]-'1';
                if (rowFlags[i][t]) return; //row invaild
                rowFlags[i][t] = true;
                if (columnFlags[j][t]) return; //column invaild
                columnFlags[j][t] = true;
                if (blockFlags[(i/3)*3 + j/3][t]) return; //block invaild
                blockFlags[(i/3)*3 + j/3][t] = true;
            }
        }

        solveSudokuRecursive(board, 0, rowFlags, columnFlags, blockFlags);
    }
};