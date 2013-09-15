class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        static const int kError = 0; 
        // the empty string
        if (NULL == str) return kError;
        
        int i = 0;
        bool isNeg = false;
        
        // find the first not blank charcter
        for (;'\0' != str[i] && ' ' == str[i]; ++i);
        
        if ('-' == str[i])
        {
            isNeg = true;
            ++i;
        }
        else if ('+' == str[i])
        {
            ++i;
        }
        
        // find the first not zero charcter
        for (;'\0' != str[i] && '0' == str[i]; ++i);
        
        double result = 0;
        while('\0' != str[i])
        {       
            if (str[i]-'0' < 0 || str[i] - '0' > 9)
                break;
                
            result *= 10;
            result += str[i] - '0';
            
            if (result < 0) break;
            
            ++i;
        }
        
        if (!isNeg && result < 0) return 0x7FFFFFFF;
        if (isNeg && result < 0) return 0x80000000;
        
        if (!isNeg && result > 0x7FFFFFFF) return 0x7FFFFFFF;
        if (isNeg && result > 0x80000000) return 0x80000000;
        
        return isNeg ? -result : result;
        
    }
};