class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (1 > n) return "";
        if (1 == n) return "1";
        string ret = "1";
        for (int i = 1; i < n; ++i) {
            int j = 1, count = 1;
            string s;
            while (j < ret.length()) {
                if (ret[j] == ret[j-1]) {
                    ++count;
                } else {
                    s += static_cast<char>(count + '0');
                    s += ret[j-1];
                    count = 1;
                }
                ++j;
            }
            s += static_cast<char>(count + '0');
            s += ret[j-1];
            ret = s;
        }
        return ret;
    }
};