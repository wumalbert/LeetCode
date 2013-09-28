class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.length(), n = T.length();
        
        if (m < n) return 0;
        
        // f[i][j]: number of subsequences of T[0,i) in S[0,j)
        // f[i][j] = T[i] == S[j] ? f[i-1][j-1] + f[i][j-1] : F[i][j-1]
        vector<vector<int> > distincted(2, vector<int>(m+1, 1));
        
        int target = 1;
        for (int i = 1; i <= n; ++i)
        {
            distincted[target][i-1] = 0;
            for (int j = i; j <= m; ++j)
            {
                if (S[j-1] == T[i-1])
                    distincted[target][j] = distincted[1-target][j-1] + distincted[target][j-1];
                else
                    distincted[target][j] = distincted[target][j-1];
            }
            target = 1 - target;
        }
        
        return distincted[1-target][m];
    }
};