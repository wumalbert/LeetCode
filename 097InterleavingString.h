class Solution01 {
private:
    bool isInterleaveRecursive(string& s1, int i1, string& s2, int i2, string& s3, int i3)
    {
        if (i1 == s1.length() && i2 == s2.length()) return true;
        
        if (i1 < s1.length() && s1[i1] == s3[i3] && isInterleaveRecursive(s1, i1+1, s2, i2, s3, i3+1))
            return true;
        if (i2 < s2.length() && s2[i2] == s3[i3] && isInterleaveRecursive(s1, i1, s2, i2+1, s3, i3+1))
            return true;
            
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s1.length() + s2.length() != s3.length()) return false;
        
        return isInterleaveRecursive(s1, 0, s2, 0, s3, 0);
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();

        if (len1 + len2 != len3) return false;

        vector<bool> interleaved(len2+1, false);

        interleaved[0] = true;
        for (int j = 1; j <= len2 && s2[j-1] == s3[j-1]; ++j)
        {
            interleaved[j] = true;
        }

        for (int i = 1; i <= len1; ++i)
        {
            interleaved[0] = interleaved[0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= len2; ++j)
            {
                interleaved[j] = (s1[i-1] == s3[i+j-1] && interleaved[j]) ||
                    (s2[j-1] == s3[i+j-1] && interleaved[j-1]);
            }
        }

        return interleaved[len2];
    }
};