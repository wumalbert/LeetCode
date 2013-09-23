class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> paths(n, 1);
        
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                paths[j] = paths[j-1] + paths[j];
            }
        }
        
        return paths[n-1];
    }
};