class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const char *c = s;
        while (*c != '\0') ++c;
        for (--c; c >= s && *c == ' '; --c);
        int count = 0;
        while (c >= s && *c != ' ') {
            ++count;
            --c;
        }
        return count;
    }
};
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const char *c = s;
        int len = 0;
        for (const char *c = s; *c != '\0'; ++c) {
            if (*c == ' ') {
                len = 0;
            } else {
                ++len;
            }
        }
        return len;
    }
};