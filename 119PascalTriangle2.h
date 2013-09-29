class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > row(2, vector<int>(rowIndex+1, 1));
        
        int target = 1;
        
        for (int i = 0; i <= rowIndex; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                row[target][j] = row[1-target][j-1] + row[1-target][j];
            }
            target = 1 - target;
        }
        
        return row[1-target];
    }
};