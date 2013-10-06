#include <vector>

using namespace std;
class Solution02 {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s || !p) return false;
        if ('\0' == *p) return '\0' == *s;
        if (*s == *p || ('\0' != *s && '?' == *p)) {
            return isMatch(s+1, p+1);
        } else if ('*' == *p) {
            for (; '*' == *p; ++p);
            while ('\0' != *s) {
                if (isMatch(s, p)) return true;
                ++s;
            }
            if (isMatch(s, p)) return true;
            return false;
        }
        return false;
    }
};
class Solution01 {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!s || !p) return false;
        int len_s = strlen(s), len_p = strlen(p);
        int number_star = 0;
        for (const char *c = p; '\0' != *c; ++c)
            if ('*' == *c) ++number_star;
        if (len_s + number_star < len_p) return false;
        vector<vector<bool> > matched(2, vector<bool>(len_s+2, false));
        matched[0][0] = true;
        int target = 1;
        for (int i = 1; i <= len_p; ++i) {
            if ('*' != p[i-1]) {
                matched[target][0] = false;
                for (int j = 1; j <= len_s; ++j) {
                    matched[target][j] = matched[1-target][j-1] && (p[i-1] == s[j-1] || '?' == p[i-1]);
                }
            } else {
                matched[target][0] = matched[1-target][0];
                for (int j = 1; j <= len_s; ++j) {
                    matched[target][j] = matched[target][j-1] || matched[1-target][j];
                }
            }
            target = 1 - target;
        }
        return matched[1-target][len_s];
    }
};
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!s || !p) return false;
        int len_s = strlen(s), len_p = strlen(p);
        int number_not_star = 0;
        for (const char *c = p; '\0' != *c; ++c)
            if ('*' != *c) ++number_not_star;
        if (len_s < number_not_star) return false;
        vector<bool> matched(len_s+1, false);
        matched[0] = true;
        for (int i = 1; i <= len_p; ++i) {
            if (i > 1 && '*' == p[i-1] && p[i-2] == p[i-1]) continue;
            if ('*' != p[i-1]) {
                for (int j = len_s; j > 0; --j) {
                    matched[j] = matched[j-1] && (p[i-1] == s[j-1] || '?' == p[i-1]);
                }
                matched[0] = false;
            } else {
                for (int j = 1; j <= len_s; ++j) {
                    matched[j] = matched[j-1] || matched[j];
                }
            }
        }
        return matched[len_s];
    }
};