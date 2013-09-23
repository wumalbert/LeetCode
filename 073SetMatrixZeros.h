class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // set the first row zero mask
        for (int i = 0; i < n; ++i)
        {
            if (!matrix[0][i])
            {
                firstRowHasZero = true;
                break;
            }
        }
        
        // set the first column zero mask
        for (int i = 0; i < m; ++i)
        {
            if (!matrix[i][0])
            {
                firstColHasZero = true;
                break;
            }
        }
        
        // store each row zero mask in the first element of the row (the first column)
        // store each column zero mask in the first element of the column (the first row)
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set the rows to zero
        for (int i = 1; i < m; ++i)
        {
            if (!matrix[i][0])
            {
                for (int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        
        // set the columns to zero
        for (int i = 1; i < n; ++i)
        {
            if (!matrix[0][i])
            {
                for (int j = 1; j < m; ++j)
                    matrix[j][i] = 0;
            }
        }
        
        // set the first row to zero
        if (firstRowHasZero)
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
                
        if (firstColHasZero)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};