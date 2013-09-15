#include <limits>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        
        static const int kCharacterNumber = 256;
        
        // the last location of a character
        int characterLastLocation[kCharacterNumber];
        for (int i = 0; i < kCharacterNumber; ++i)
            characterLastLocation[i] = -1;
        
        // the substring length between two same character
        static const int kNorepeatLength = numeric_limits<int>::max();
        int *characterIntevalLength = new int[s.length()];
        for (size_t i = 0; i < s.length(); ++i)
            characterIntevalLength[i] = kNorepeatLength;
        
        for (size_t i = 0; i < s.length(); ++i)
        {
            int index = s[i]-'0';
            if (characterLastLocation[index] >= 0)
            {
                characterIntevalLength[i] = i - characterLastLocation[index];
            }
            characterLastLocation[index] = i;
        }
        
        int curLength = 1;
        int maxLength = 1;
        for (size_t i = 1; i < s.length(); ++i)
        {
            if (curLength < characterIntevalLength[i])
            {
                curLength += 1;
                if (curLength > maxLength) maxLength = curLength;
            }
            else
            {
                curLength = characterIntevalLength[i];
            }
        }
        
        delete [] characterIntevalLength;
        
        return maxLength;
    }
};