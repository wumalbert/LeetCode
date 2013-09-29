class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        
        for (int i = 1; i <= numRows; ++i)
        {
            ret.push_back(vector<int>(i, 1));
            
            for (int j = 1; j < i-1; ++j)
            {
                ret[i-1][j] = ret[i-2][j-1] + ret[i-2][j];
            }
        }
        
        return ret;
    }
};