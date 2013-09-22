class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret(n, vector<int>(n, 0));
        
        int count = 0;
        int step = (n + 1) / 2;
        for (int i = 0; i < step; ++i)
        {
            int bottom = n-1-i;
            // the +1 horizontal direction
            for (int j = i; j <= bottom; ++j)
                ret[i][j] = ++count;
            
            // the +1 vertical direction
            for (int j = i+1; j <= bottom; ++j)
                ret[j][bottom] = ++count;
            
            // the -1 horizontal direction
            if (bottom == i) continue;
            
            for (int j = bottom-1; j >= i; --j)
                ret[bottom][j] = ++count;
                
            // the -1 vertical direction
            for (int j = bottom-1; j > i; --j)
                ret[j][i] = ++count;
        }
        return ret;
    }
};