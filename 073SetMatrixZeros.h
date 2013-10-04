class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool first_row_mask = false, first_column_mask = false;  // indicate whether it should be set zero
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; ++j) {
            if (0 == matrix[0][j]) {
                first_row_mask = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (0 == matrix[i][0]) {
                first_column_mask = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (0 == matrix[i][0]) {
                for (int j = 1; j < n; ++j) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (0 == matrix[0][j]) {
                for (int i = 1; i < m; ++i) matrix[i][j] = 0;
            }
        }
        if (first_row_mask) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (first_column_mask) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};