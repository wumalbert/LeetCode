class Solution01 {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (!s || !p) return false;
        if ('\0' == *p) return '\0' == *s;
        if ('*' != *(p+1)) {
            if (*s == *p || ('.' == *p && '\0' != *s)) return isMatch(s+1, p+1);
            else return false;
        } else {
            if (isMatch(s, p+2)) return true; // zero
            while (*s == *p || ('.' == *p && '\0' != *s)) { // more of the preceding element
                if (isMatch(s+1, p+2)) return true;
                ++s;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (!s || !p) return false;
        if ('\0' == *p) return '\0' == *s;
        int len_s = strlen(s), len_p = strlen(p);
        vector<vector<bool> > matched(len_p+1, vector<bool>(len_s+1, false));
        matched[0][0] = true;
        for (int i = 1; i <= len_p; ++i) {
            if ('*' != p[i-1]) {
                matched[i][0] = false;
                for (int j = 1; j <= len_s; ++j) {
                    matched[i][j] = matched[i-1][j-1] && (p[i-1] == s[j-1] || '.' == p[i-1]);
                }
            } else {
                matched[i][0] = matched[i-2][0];
                for (int j = 1; j <= len_s; ++j) {
                    matched[i][j] = matched[i-2][j] || (matched[i][j-1] && (p[i-2] == s[j-1] || '.' == p[i-2]));
                }
            }
        }
        return matched[len_p][len_s];
    }
};
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (!s || !p) return false;
        int len_s = strlen(s), len_p = strlen(p);
        vector<vector<bool> > matched(3, vector<bool>(len_s+1, false));
        matched[0][0] = true;
        int first = 0, second = 0, target = 1;
        for (int i = 1; i <= len_p; ++i) {
            if ('*' != p[i-1]) {
                matched[target][0] = false;
                for (int j = 1; j <= len_s; ++j) {
                    matched[target][j] = matched[second][j-1] && (p[i-1] == s[j-1] || '.' == p[i-1]);
                }
            } else {
                matched[target][0] = matched[first][0];
                for (int j = 1; j <= len_s; ++j) {
                    matched[target][j] = matched[first][j] || (matched[target][j-1] && (p[i-2] == s[j-1] || '.' == p[i-2]));
                }
            }
            first = second;
            second = target;
            target = 3 - first - second;
        }
        return matched[second][len_s];
    }
};