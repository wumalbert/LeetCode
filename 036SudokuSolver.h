class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> masks(kWidth*3, 0);
        for (int i = 0; i < kWidth; ++i) {
            for (int j = 0; j < kWidth; ++j) {
                if ('.' == board[i][j]) continue;
                int value = 1 << (board[i][j]-'1'), column = kWidth+j, block = kWidth*2 + i/3*3 + j/3;
                if (masks[i]&value || masks[column]&value || masks[block]&value) return;
                masks[i] = masks[i]|value;
                masks[column] = masks[column]|value;
                masks[block] = masks[block]|value;
            }
        }
        solve(board, masks, 0);
    }
private:
    bool solve(vector<vector<char> > &board, vector<int> &masks, int index) {
        if (kSize == index) return true;
        int row = index / kWidth, column = index % kWidth;
        if ('.' == board[row][column]) {
            int column_index = kWidth + column, block_index = kWidth*2 + row/3*3 + column/3;
            for (int i = 0; i < kWidth; ++i) {
                int value = 1 << i;
                if (masks[row]&value || masks[column_index]&value || masks[block_index]&value) continue;
                masks[row] = masks[row]|value;
                masks[column_index] = masks[column_index]|value;
                masks[block_index] = masks[block_index]|value;
                board[row][column] = static_cast<char>('1'+i);
                if (solve(board, masks, index+1)) return true;
                masks[row] = masks[row]^value;
                masks[column_index] = masks[column_index]^value;
                masks[block_index] = masks[block_index]^value;
                board[row][column] = '.';
            }
        } else if (solve(board, masks, index+1)) {
            return true;
        }
        return false;
    }
    static const int kWidth = 9, kSize = 81;
};