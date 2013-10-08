class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(); 
        vector<int> paths(n, numeric_limits<int>::max());
        paths[0] = 0; 
        for (int i = 0; i < m; ++i) {
            paths[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                paths[j] = min(paths[j-1], paths[j]) + grid[i][j];
            }
        } 
        return paths[n-1];
    }
};