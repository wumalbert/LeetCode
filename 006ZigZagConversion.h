class Solution01 {
public:
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int len = s.length();
        vector<string> rows(nRows, "");
        int cycle_length = 2*nRows-2;
        for (int i = 0; i < len; ) {
            int j;
            for (j = 0; j < nRows && i < len; ++j) {
                rows[j] += s[i++];
            }
            for (j = cycle_length - j; j > 0 && i < len; --j) {
                rows[j] += s[i++];
            }
        }
        string ret;
        for (int i = 0; i < nRows; ++i) ret += rows[i];
        return ret;
    }
};
class Solution {
public:
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case. 
        if (1 == nRows) return s;
        int len = s.length(), step = 2*nRows-2;
        string ret(len, ' ');
        for (int i = 0, count = 0; i < nRows; ++i) {
            for (int j = i; j < len; j += step) {
                ret[count++] = s[j];
                if (i != 0 && i != nRows-1 && j + 2*(nRows-i) - 2 < len)
                    ret[count++] = s[j + 2*(nRows-i) - 2];
            }
        }
        return ret;
    }
};