class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return vector<vector<int> >();
        vector<vector<int> > ret(n, vector<int>(n, 0));
        for (int i = 0, number = 0; i < (n+1)/2; ++i) {
            for (int j = i; j < n-i; ++j) {
                ret[i][j] = ++number;
            }
            for (int j = i+1; j < n-i; ++j) {
                ret[j][n-i-1] = ++number;
            }
            for (int j = n-i-2; j >= i; --j) {
                ret[n-i-1][j] = ++number;
            }
            for (int j = n-i-2; j > i; --j) {
                ret[j][i] = ++number;
            }
        }
        return ret;
    }
};