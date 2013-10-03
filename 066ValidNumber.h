// Simple straight forward iteration
class Solution01 {
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
// More elegant iteration
class Solution02 {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // skip the whitespace in the beginning of the string
        if (!s) return false;
        while (*s && isspace(*s)) ++s;
        // skip the '+' '-' 
        if (*s && ('+' == *s || '-' == *s)) ++s;
        bool exponent_mask = false, dot_mask = false, left_mask = false, right_mask = false;
        while (*s) {
            if (isdigit(*s)) {
                if (exponent_mask) right_mask = true;
                else left_mask = true;
            } else if ('+' == *s || '-' == *s) {
                if ('e' != *(s-1) && 'E' != *(s-1)) return false;
            } else if ('.' == *s) {
                if (dot_mask || exponent_mask) return false;
                dot_mask = true;
            } else if ('e' == *s || 'E' == *s) {
                if (exponent_mask || !left_mask) return false;
                exponent_mask = true;
            } else if (isspace(*s)) {
                break;
            } else {
                return false;
            }
            ++s;
        }
        while (*s && isspace(*s)) ++s;
        if (*s || (!left_mask && !right_mask) || (exponent_mask && !right_mask)) return false;  // ".", "", "123e"
        return true;
    }
};
// automatic state model
class Solution {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        enum InputType {
            INVALID = 0,
            SPACE = 1,
            SIGN = 2,
            DIGIT = 3,
            DOT = 4,
            EXPONENT = 5,
            NUMBER_INPUT = 6
        };
        
        int transition_table [][NUMBER_INPUT] = {
            -1,  0,  1,  2,  3, -1,  // state 0: ""
            -1, -1, -1,  2,  3, -1,  // state 1: "+", "-"
            -1,  8, -1,  2,  4,  5,  // state 2: "1"
            -1, -1, -1,  4, -1, -1,  // state 3: "."
            -1,  8, -1,  4, -1,  5,  // state 4: "1."
            -1, -1,  6,  7, -1, -1,  // state 5: "1e"
            -1, -1, -1,  7, -1, -1,  // state 6: "1e+"
            -1,  8, -1,  7, -1, -1,  // state 7: "1e1"
            -1,  8, -1, -1, -1, -1   // state 8: "1 "
        };
        int state = 0;
        while (*s) {
            InputType input = INVALID;
            if (isspace(*s)) {
                input = SPACE;
            } else if ('+' == *s || '-' == *s) {
                input = SIGN;
            } else if (isdigit(*s)) {
                input = DIGIT;
            } else if ('.' == *s) {
                input = DOT;
            } else if ('e' == *s || 'E' == *s) {
                input = EXPONENT;
            } 
            state = transition_table[state][input];
            if (-1 == state) return false;
            ++s;
        }
        if (2 == state || 4 == state || 7 == state || 8 == state) return true;
        else return false;
    }
};