class Solution {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // skip the whitespace in the beginning of the string
        if (!s) return false;
        while (*s && (' ' == *s || '\t' == *s)) ++s;
        if (!*s) return false;  // all whitespace
        // skip the whitespace in the end of the string
        const char *end;
        for (end = s; *end; ++end) {}
        for (--end; ' ' == *end || '\t' == *end; --end) {}
        ++end;
        // the sign symbol
        if ('+' == *s || '-' == *s) { 
            ++s;
            if (s == end) return false;  // "+", "-"
        }
        bool exponent_mask = false, dot_mask = false;
        if ('e' == *s || 'E' == *s) {  // "e12"
            return false;
        } else if ('.' == *s) {
            if (!isdigit(*(s+1))) return false;  // ".", ".e"
            dot_mask = true;
            ++s;
        }
        while (s != end) {
            if (isdigit(*s)) {
                ++s;
            } else if ('.' == *s && !dot_mask && !exponent_mask) { // ".12.", "e1." 
                dot_mask = true;
                ++s;
            } else if (('e' == *s || 'E' == *s) && !exponent_mask) { // "12e2e"
                exponent_mask = true;
                ++s;
                if (s == end) { // "12e"
                    return false; 
                }
                else if ('+' == *s || '-' == *s) { 
                    if (s+1 == end) return false; // "12e+"
                    ++s;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};