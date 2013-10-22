class Solution01 {
private:
    bool isInterleaveRecursive(string& s1, int i1, string& s2, int i2, string& s3, int i3) {
        if (i1 == s1.length() && i2 == s2.length()) return true;
        if (i1 < s1.length() && s1[i1] == s3[i3] && isInterleaveRecursive(s1, i1+1, s2, i2, s3, i3+1))
            return true;
        if (i2 < s2.length() && s2[i2] == s3[i3] && isInterleaveRecursive(s1, i1, s2, i2+1, s3, i3+1))
            return true;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() + s2.length() != s3.length()) return false;
        return isInterleaveRecursive(s1, 0, s2, 0, s3, 0);
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() + s2.length() != s3.length()) return false;
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        vector<bool> interleaved(len2+1, false);
        interleaved[0] = true;
        for (int j = 1; j <= len2 && s2[j-1] == s3[j-1]; ++j)
            interleaved[j] = true;
        for (int i = 1; i <= len1; ++i) {
            interleaved[0] = interleaved[0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= len2; ++j)
                interleaved[j] = (s1[i-1] == s3[i+j-1] && interleaved[j]) 
                                || (s2[j-1] == s3[i+j-1] && interleaved[j-1]);
        }
        return interleaved[len2];
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() + s2.length() != s3.length()) return false;
        int m = s1.length(), n = s2.length();
        vector<vector<bool> > interleaved(m+1, vector<bool>(n+1, false));
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    interleaved[i][j] = true;
                    continue;
                }
                interleaved[i][j] = (i >= 1 && s1[i-1] == s3[i+j-1] && interleaved[i-1][j]) 
                                    || (j >= 1 && s2[j-1] == s3[i+j-1] && interleaved[i][j-1]);
            }
        return interleaved[m][n];
    }
};