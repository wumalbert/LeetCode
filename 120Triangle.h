class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = triangle.size();
        vector<vector<int> > sum(2, vector<int>(row, 0));
        sum[0][0] = triangle[0][0];
        
        int target = 1;
        for (int i = 1; i < row; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                sum[target][j] = numeric_limits<int>::max();
                if (j > 0) sum[target][j] = min(sum[target][j], sum[1-target][j-1] + triangle[i][j]);
                if (j < i) sum[target][j] = min(sum[target][j], sum[1-target][j] + triangle[i][j]);
            }
            target = 1 - target;
        }
        
        target = 1 - target;
        int minSum = sum[target][0];
        for (int i = 1; i < row; ++i)
        {
            if (sum[target][i] < minSum) minSum = sum[target][i];
        }
        
        return minSum;
    }
};