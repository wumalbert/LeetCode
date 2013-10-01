class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty()) return true;
        int len = s.length();
        
        const char *begin = s.data(), *end = begin+(len-1);
        while(begin < end)
        {
            char c1 = *begin;
            char c2 = *end;
            if (!isalpha(c1) && !isdigit(c1))
            {
                ++begin;
                continue;
            }
            if (!isalpha(c2) && !isdigit(c2))
            {
                --end;
                continue;
            }
            
            if (isalpha(c1)) c1 = tolower(c1);
            if (isalpha(c2)) c2 = tolower(c2);
            if (c1 != c2) return false;
            
            ++begin;
            --end;
        }
        return true;
    }
};