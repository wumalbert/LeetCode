class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!str) return 0;
        
        long long ret = 0;
        bool negetive = false;
        const char *p = str;
        // skip the whitespace
        while('\0' != *p && (' ' == *p || '\t' == *p)) ++p;
        // get the sign mask
        if ('-' == *p) {
            negetive = true;
            ++p;
        }
        else if('+' == *p) ++p;
        
        while(isdigit(*p)) {
            ret *= 10;
            ret += *p - '0';
            ++p;
        }
        if(negetive) ret = -ret;
        
        if(ret > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        else if(ret < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        else return ret;
    }
};