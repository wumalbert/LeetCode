class Solution {
public:
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return 0;
        int first = 0, second = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (!isdigit(s[i])) return 0;
            int t = 0;
            if ('0' != s[i]) t += second;
            if (i > 0 && '1' == s[i-1] || ('2' == s[i-1] && '7' > s[i])) t += first;
            first = second;
            second = t;
        }
        return second;
    }
};