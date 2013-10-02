class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!str) return 0;
        
        long long ret = 0;
        bool negetive = false, start = false;
        const char *p = str;
        while('\0' != *p && (' ' == *p || '\t' == *p)) ++p;
        while('\0' != *p)
        {
            if(isdigit(*p))
            {
                start = true;
                ret *= 10;
                ret += *p - '0';
            }
            else if('-' == *p && !start)
            {
                negetive = true;
                start = true;
            }
            else if('+' == *p && !start)
            {
                start = true;
            }
            else break;
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