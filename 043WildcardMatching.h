#include <vector>

using namespace std;

class Solution {
public:
    bool isMatchRecursive(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s || !p) return false;
        
        if ('\0' == *s && '\0' == *p) return true;
        
        if (*s == *p || ('\0' != *s && '?' == *p))
        {
            return isMatchRecursive(s+1, p+1);
        }
        else if ('*' == *p)
        {
            for (; '*' == *p; ++p);
            while ('\0' != *s)
            {
                if (isMatchRecursive(s, p)) return true;
                ++s;
            }
            if (isMatchRecursive(s, p)) return true;
            return false;
        }
        else return false;
    }

    bool isMatch02(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (!s || !p) return false;
        // using daynamic programming method
        int m = strlen(s); // the length of string
        int n = strlen(p); // the length of pattern

        int count = 0;
        for (int i = 0; p[i] != '\0'; ++i)
            if (p[i] != '*') ++count;
        if (count > m) return false;

        vector<bool> match(m+1, false);
        match[0] = true;

        for (int i = 0; i < n; ++i)
        {
            if ('*' == p[i] && i > 1 && p[i] == p[i-1]) continue;

            if ('*' == p[i])
            {
                for (int j = 1; j <= m; ++j)
                {
                    match[j] = match[j] | match[j-1];
                }
            }
            else
            {
                for (int j = m; j > 0; --j)
                {
                    if (p[i] == s[j-1] || '?' == p[i])
                        match[j] = match[j-1];
                    else
                        match[j] = false;
                }
                match[0] = false;
            }
        }

        return match[m];
    }

    bool isMatch03(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!*s && !*p) return true;

        int ms_max = 1;//size of *s
        const char* ss = s;
        while(*ss){ ++ms_max;++ss;}
        int np_max = 1;
        const char* pp = p;
        while(*pp){if(*pp!='*')++np_max;++pp;}
        if(ms_max < np_max) return false;

        vector<vector<bool> > r(2, vector<bool>(ms_max, false));
        bool flag = 1;
        r[0][0] = true;
        do{//*p
            int ms = 1;
            ss = s;
            if (*p == '*'){
                while(*p == '*') ++p;
                --p;
                r[flag][0] = r[!flag][0];
                for( ;ms <= ms_max; ++ms){//up and left
                    if (r[!flag][ms] || r[flag][ms-1]) break;
                    else r[flag][ms] = false;
                }
                for(;ms <= ms_max; ++ms){
                    r[flag][ms] = true;
                }
            }
            else{
                do{
                    bool r_flag = false;
                    if (*ss == *p || *p == '?'){
                        r_flag = r[!flag][ms-1];//diagnal
                    }
                    r[flag][ms]=r_flag;
                    ++ms;++ss;
                }while(*ss);//*s
                r[flag][0] = false;
            }
            ++p;
            flag = !flag;
        }while(*p);
        return r[!flag][ms_max-1];
    }

    bool isMatch04(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int len_s = strlen(s), len_p = strlen(p);
        if (!len_p) return !len_s;

        // -->Hack for last test case
        int count_p = 0;
        const char* ptr = p;
        while (*ptr) {
            if (*ptr != '*')
                count_p ++;
            ptr++;
        }

        if (count_p > len_s)
            return false;
        // <--

        bool match[len_p];
        match[0] = p[0] == '*';
        for (int i=1; i<len_p; i++)
            match[i] = match[i-1] && p[i] == '*';

        bool diagnal = true;
        for (int row=0; row<len_s; row++) {
            bool left = false;
            for (int col=0; col<len_p; col++) {
                bool m = p[col] == '*' && (diagnal || left || match[col]) ||
                    (p[col] == '?' || p[col] == s[row]) && diagnal;
                diagnal = match[col];
                left = match[col] = m;
            }
            diagnal = false;
        }
        return match[len_p-1];
    }
};