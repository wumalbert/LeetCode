class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s) return 0;
        
        // 1. find the end of string
        const char *start = s, *end = s;
        for (end = s; '\0' != *end; ++end);
        
        // 2. find the last not ' ' character 
        for (--end; end != s-1 && ' ' == *end; --end);
        
        if (end == s-1) return 0;
        
        // 3. find the start postion of the last word
        for (start = end; start != s-1 && ' ' != *start; --start);
        
        return end - start;
    }
};