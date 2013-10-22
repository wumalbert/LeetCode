class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        vector<vector<vector<bool> > > scrambled(len, vector<vector<bool> >(len, vector<bool>(len+1, false)));
        for (int i = 0; i < len; ++i) 
            for (int j = 0; j < len; ++j) {
                scrambled[i][j][0] = true;
                scrambled[i][j][1] = s1[i] == s2[j];
            }
        for (int l = 2; l <= len; ++l) 
            for (int i = 0; i <= len-l; ++i) 
                for (int j = 0; j <= len-l; ++j) 
                    for (int k = 1; k < l; ++k) {
                        if ((scrambled[i][j+l-k][k] && scrambled[i+k][j][l-k]) || (scrambled[i][j][k] && scrambled[i+k][j+k][l-k])) {
                            scrambled[i][j][l] = true;
                            break;
                        }
                    }
        return scrambled[0][0][len];
    }
};
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() != s2.length()) return false;
        return solve(s1, 0, s2, 0, s1.length());
    }
private:
    bool solve(const string &s1, int pos1, const string &s2, int pos2, int len) {
        if (len == 0) return true;
        if (len == 1) return s1[pos1] == s2[pos2];
        for (int l = 1; l < len; ++l) {
            if ((solve(s1, pos1, s2, pos2, l) && solve(s1, pos1+l, s2, pos2+l, len-l))
                || (solve(s1, pos1, s2, pos2+len-l, l) && solve(s1, pos1+l, s2, pos2, len-l)))
                return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        vector<vector<vector<int> > > mask(len, vector<vector<int> >(len, vector<int>(len+1, -1)));
        return solve(s1, 0, s2, 0, s1.length(), mask);
    }
private:
    int solve(const string &s1, int pos1, const string &s2, int pos2, int len, vector<vector<vector<int> > > &mask) {
        if (mask[pos1][pos2][len] != -1) return mask[pos1][pos2][len];
        if (len == 0) return mask[pos1][pos2][len] = 1;
        if (len == 1) return mask[pos1][pos2][len] = s1[pos1] == s2[pos2] ? 1 : 0;
        for (int l = 1; l < len; ++l) {
            if ((solve(s1, pos1, s2, pos2, l, mask) && solve(s1, pos1+l, s2, pos2+l, len-l, mask))
                || (solve(s1, pos1, s2, pos2+len-l, l, mask) && solve(s1, pos1+l, s2, pos2, len-l, mask)))
                return mask[pos1][pos2][len] = 1;
        }
        return mask[pos1][pos2][len] = 0;
    }
};