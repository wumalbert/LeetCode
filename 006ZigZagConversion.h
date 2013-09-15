class Solution {
private:
    string convert01(string s, int nRows)
    {
        string* dst = new string[nRows];
        
        int stepInterval = 2 * nRows - 2;
        
        int i = 0;
        while (i < s.length())
        {
            int j = 0;
            for (; j < nRows && i < s.length(); ++j)
                dst[j] += s[i++];
            for (; j < stepInterval && i < s.length(); ++j)
                dst[stepInterval - j] += s[i++];
        }
        
        string result;
        for (int i = 0; i < nRows; ++i)
            result += dst[i];
        
        delete [] dst;
        
        return result;
    }
    
    string converst02(string s, int nRows)
    {
        if (1 == nRows) return s;
        
        int step = 2 * nRows - 2;
        
        string dst;
        for(int i = 0; i < nRows; ++i)
        {
            int j = i;
            while (j < s.length())
            {
                dst += s[j];
                
                if (j%step != 0 && 2*(nRows-i)-2 != 0 && j+2*(nRows-i)-2 < s.length())    
                    dst += s[j+2*(nRows-i)-2];
                    
                j += step;
            }
        }
        
        return dst;
    }
    
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        return converst02(s, nRows);
    }
};