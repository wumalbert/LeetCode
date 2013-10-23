class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (S.length() < T.length()) return 0;
        int m = S.length(), n = T.length(), target = 1;
        vector<vector<int> > distincted(2, vector<int>(m+1, 1));
        for (int i = 1; i <= n; ++i) {
            distincted[target][i-1] = 0;
            for (int j = i; j <= m; ++j) {
                if (T[i-1] != S[j-1]) distincted[target][j] = distincted[target][j-1];
                else distincted[target][j] = distincted[target][j-1] + distincted[1-target][j-1];
            }
            target = 1 - target;
        }
        return distincted[1-target][m];
    }
};
class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (S.length() < T.length()) return 0;
        int m = S.length(), n = T.length(), target = 1;
        vector<int> distincted(n+1, 0);
        distincted[0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                distincted[j] += (S[i-1] == T[j-1]) * distincted[j-1];
            }
        }
        return distincted[n];
    }
};