class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        int ret = 0;
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        
        for (int i = 0; i < m; ++i)
        {
            int l = 0;
            for (int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    ++height[j];
                    left[j] = max(left[j], l);
                }
                else
                {
                    height[j] = left[j] = 0;
                    l = j+1;
                    right[j] = n;
                }
            }
            
            int r = n;
            for (int j = n-1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], r);
                    if (ret < height[j] * (right[j] - left[j])) ret = height[j] * (right[j] - left[j]);
                }
                else r = j;
            }
        }
        
        return ret;
    }
};