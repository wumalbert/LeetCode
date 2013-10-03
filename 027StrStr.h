// Bruce force solution
class Solution01 {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!haystack || !needle) return NULL;
        if (!*needle) return haystack;
        while (*haystack) {
            char *ch1 = haystack, *ch2 = needle;
            while (*ch1 && *ch2 && *ch1 == *ch2) {
                ++ch1;
                ++ch2;
            }
            if (!*ch2) return haystack;
            else if (!*ch1) return NULL;
            else ++haystack;
        }
        return NULL;
    }
};
// KMP algorithm
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!haystack || !needle) return NULL;
        if (!*needle) return haystack;
        int n = strlen(haystack), m = strlen(needle);
        // build the next array, when i mismatch go to next[i]
        vector<int> next(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = next[i-1];
            while (j != -1 && needle[i-1] != needle[j]) {
                j = next[j];
            }
            next[i] = j+1;
        }
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (needle[j] == haystack[i]) {
                ++j;
                ++i;
            } else {
                j = next[j];
                if (-1 == j) {
                    ++i;
                    ++j;
                }
            }
        }
        if (j == m) return haystack + i - m;
        else return NULL;
    }
};