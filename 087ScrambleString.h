class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() != s2.length()) return false;
        
        int len = s1.length();
        vector<vector<vector<bool> > > scrambled(len, 
            vector<vector<bool> >(len, vector<bool>(len+1, false)));
            
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                scrambled[i][j][0] = true;
                scrambled[i][j][1] = s1[i] == s2[j];
            }
        }
        
        for (int l = 2; l <= len; ++l)
        {
            for (int i = 0; i <= len-l; ++i)
            {
                for (int j = 0; j <= len-l; ++j)
                {
                    scrambled[i][j][l] = false;
                    for (int k = 1; k < l; ++k)
                    {
                        if ((scrambled[i][j][k] && scrambled[i+k][j+k][l-k])
                            || (scrambled[i][j+l-k][k] && scrambled[i+k][j][l-k]))
                        {
                            scrambled[i][j][l] = true;
                            break;
                        }
                    }
                    
                }
            }
        }
        
        return scrambled[0][0][len];
    }
};