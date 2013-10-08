class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> paths(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                paths[j] = paths[j-1] + paths[j];
            }
        }
        return paths[n-1];
    }
};