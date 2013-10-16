class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        static const int kSize = 9;
        vector<int> masks(kSize*3, 0);
        for (int i = 0; i < kSize; ++i) {
            for (int j = 0; j < kSize; ++j) {
                if ('.' == board[i][j]) continue;
                int value = 1 << (board[i][j]-'1'), row = i, column = kSize+j, block = kSize*2 + i/3*3 + j/3;
                if (masks[row]&value || masks[column]&value || masks[block]&value) return false;
                masks[row] = masks[row]|value;
                masks[column] = masks[column]|value;
                masks[block] = masks[block]|value;
            }
        }
        return true;
    }
};