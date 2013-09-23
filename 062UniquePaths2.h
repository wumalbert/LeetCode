class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        if (obstacleGrid.empty()) return 0;
        int n = obstacleGrid[0].size();
        
        vector<int> paths(n, 0);
        paths[0] = 1;
            
        for (int i = 0; i < m; ++i)
        {
            if (1 == obstacleGrid[i][0])
                paths[0] = 0;
            for (int j = 1; j < n; ++j)
            {
                if (1 == obstacleGrid[i][j]) paths[j] = 0;
                else paths[j] = paths[j-1] + paths[j];
            }
        }
        
        return paths[n-1];
    }
};