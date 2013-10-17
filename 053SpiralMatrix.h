class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty()) return ret;
        int m = matrix.size(), n = matrix[0].size(), steps = (min(m, n) + 1)/2;
        for (int i = 0; i < steps; ++i) {
            for (int j = i; j < n-i; ++j) {
                ret.push_back(matrix[i][j]);
            }
            for (int j = i+1; j < m-i; ++j) {
                ret.push_back(matrix[j][n-i-1]);
            }
            if (m-i-1 > i) {
                for (int j = n-i-2; j >= i; --j) {
                    ret.push_back(matrix[m-i-1][j]);
                }
            }
            if (i < n-i-1) {
                for (int j = m-i-2; j > i; --j) {
                    ret.push_back(matrix[j][i]);
                }
            }
        }
        return ret;
    }
};