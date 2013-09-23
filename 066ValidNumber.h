class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s) return false;
        
        const char *p;
        for (p = s; '\0' != *p && ' ' == *p; ++p);
        if ('\0' == *p) return false;
        
        bool hasDot = false;
        bool hasExp = false;
        if ('.' == *p)
        {
            hasDot = true;
            char c = *(p+1);
            if ('\0' == c || ('0' > c || '9' < c)) return false;
        }
        else if (('0' > *p || '9' < *p) && '+' != *p && '-' != *p) return false;
        else if ('+' == *p || '-' == *p)
        {
            char c = *(p+1);
            if ('\0' == c || (('0' > c || '9' < c) && '.' != c)) return false;
            else if ('.' == c)
            {
                c = *(p+2);
                if ('\0' == c || ('0' > c || '9' < c)) return false;
            }
        }
        
        ++p;
        while ('\0' != *p)
        {
            if ('e' == *p)
            {
                if (hasExp) return false;
                hasExp = true;
                
                char c = *(p+1);
                if ('\0' == c) return false;
                if (('+' == c || '-' == c))
                {
                    if ('\0' == *(p+2)) return false;
                    else ++p;
                }
                else if ('0' > c || '9' < c) return false; 
                
                ++p;
                continue;
            }
            else if ('.' == *p)
            {
                if (hasDot || hasExp) return false;
                hasDot = true;
                
                ++p;
                continue;
            }
            else if (' ' == *p)
                break;
            else if ('0' > *p || '9' < *p)
                return false;
            ++p;
        }
        
        for (; '\0' != *p && ' ' == *p; ++p);
        
        return '\0' == *p;
    }
};