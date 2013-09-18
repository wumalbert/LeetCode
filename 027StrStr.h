class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!haystack || !needle) return NULL;
        
        // use KMP to find the substr
        int needleLength = 0;
        for (needleLength = 0; needle[needleLength] != '\0'; ++needleLength);
        
        if (needleLength <= 0) return haystack;
        
        int *back = new int[needleLength];
        back[0] = -1;
        
        for (int i = 1; i < needleLength; ++i)
        {
            int j = back[i-1];
            
            while (j != -1 && needle[j] != needle[i-1])
            {
                j = back[j];
            }
            
            if (j != -1) back[i] = j + 1;
            else back[i] = 0;
        }
        
        int i = 0, j = 0;
        while (haystack[i] != '\0' && needle[j] != '\0')
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = back[j];
                if (-1 == j)
                {
                    ++i;
                    ++j;
                }
            }
        }
        
        if ('\0' == needle[j]) return haystack + i - needleLength;
        
        return NULL;
    }
};