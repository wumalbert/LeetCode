#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution01 {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> chessboard(n, string(n, '.'));
        vector<vector<string> > ret;
        vector<bool> queened(6*n-2, false); // the flags, n rows, n columns, 2*n-1 positive diagonal, 2*n-1 negetive dignonal 
        dfs(n, 0, queened, chessboard, ret);
        return ret;
    }
private:
    void dfs(int n, int row, vector<bool> &queened, vector<string> &chessboard, vector<vector<string> > &result) {
        if (n == row) {
            result.push_back(chessboard);
            return;
        }
        int column_index = n, positive_diagonal_index = 2*n+row, negetive_diagonal_index = row+5*n-2;
        for (int i = 0; i < n; ++i) {
            if (!queened[column_index] && !queened[positive_diagonal_index] && !queened[negetive_diagonal_index]) {
                queened[column_index] = queened[positive_diagonal_index] = queened[negetive_diagonal_index] = true;
                chessboard[row][i] = 'Q';
                dfs(n, row+1, queened, chessboard, result);
                chessboard[row][i] = '.';
                queened[column_index] = queened[positive_diagonal_index] = queened[negetive_diagonal_index] = false;
            }
            ++column_index;
            ++positive_diagonal_index;
            --negetive_diagonal_index;
        }
    }
};
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> chessboard(n, string(n, '.'));
        vector<vector<string> > ret;
        upper_limit_ = (1 << n) - 1;
        for (int i = 0; i < n; ++i) column_index_map_[1<<i] = n-1-i;
        dfs(0, 0, 0, 0, chessboard, ret);
        return ret;
    }
private:
    void dfs(int index, int column, int left, int right, vector<string> &chessboard, vector<vector<string> > &result) {
        if (column == upper_limit_) {
            result.push_back(chessboard);
            return;
        }
        int row = upper_limit_ & ~(column | left | right);
        while (row) {
            int t = row - (row & (row-1));
            chessboard[index][column_index_map_[t]] = 'Q';
            dfs(index+1, column|t, (left|t)<<1, (right|t)>>1, chessboard, result);
            chessboard[index][column_index_map_[t]] = '.';
            row = row & (row-1);
        }
    }
    int upper_limit_;
    unordered_map<int, int> column_index_map_;
};