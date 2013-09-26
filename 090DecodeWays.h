class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        int len = s.length();
        vector<int> decoded(len+1, 1);
        
        if ('0' == s[len-1]) decoded[len-1] = 0;
        
        for (int i = len-2; i >= 0; --i)
        {
            if (s[i] > '2' || ('2' == s[i] && '6' < s[i+1]))
            {
                decoded[i] = decoded[i+1];
            }
            else if (s[i] != '0')
            {
                decoded[i] = decoded[i+1] + decoded[i+2];
            }
            else
            {
                decoded[i] = 0;
            }
        }
        
        return decoded[0];
    }
};