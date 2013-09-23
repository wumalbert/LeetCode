class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.empty()) return 0;
        int m = grid.size();
        if (grid[0].empty()) return 0;
        int n = grid[0].size();
        
        vector<int> paths(n+1, numeric_limits<int>::max());
        paths[0] = 0;
            
        for (int i = 0; i < m; ++i)
        {
            paths[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
            {
                paths[j] = min(paths[j-1], paths[j]) + grid[i][j];
            }
        }
        
        return paths[n-1];
    }
};