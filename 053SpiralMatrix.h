#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        
        if (matrix.empty()) return ret;
        if (matrix[0].empty()) return ret;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int step = min(m, n);
        step  = (step + 1) / 2;
        
        for (int i = 0; i < step; ++i)
        {
            // the row
            int bottomRow = m-i-1;
            int bottomCol = n-i-1;
            
            for (int j = i; j <= bottomCol; ++j)
                ret.push_back(matrix[i][j]);
            
            for (int j = i+1; j <= bottomRow; ++j)
                ret.push_back(matrix[j][bottomCol]);
            
            if (bottomRow > i)
            {
                for (int j = bottomCol-1; j >= i; --j)
                    ret.push_back(matrix[bottomRow][j]);
            }
            
            if (bottomCol > i)
            {
                for (int j = bottomRow-1; j > i; --j)
                    ret.push_back(matrix[j][i]);
            }
        }

        return ret;
    }
};