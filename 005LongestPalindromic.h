class Solution {
    
private:
    string preprocess(string& s)
    {
        string ns;
        ns += "^#";
        for(size_t i = 0; i < s.length(); ++i)
        {
            ns += s.substr(i, 1);
            ns += "#";
        }
        ns += "$";
        
        return ns;
    }
    
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty()) return s;
        
        int n = 2 * s.length() + 3;
        string ns = preprocess(s);
        
        int* radius = new int[n];
        int maxCenter, maxRadius;
        maxCenter = maxRadius = 0;
        for (int i = 1; i < n-1; ++i)
        {
            if (maxRadius > i)
            {
                int j = 2*maxCenter - i;
                radius[i] = (maxRadius - i) > radius[j] ? radius[j] : (maxRadius - i);
            }
            else radius[i] = 0;
            
            for (; ns[i - radius[i]- 1] == ns[i + radius[i] + 1]; ++radius[i]);
            
            if (i + radius[i] > maxRadius)
            {
                maxCenter = i;
                maxRadius = i + radius[i];
            }
        }
        
        maxCenter = maxRadius = 0;
        for (int i = 1; i < n-1; ++i)
        {
            if (radius[i] > maxRadius)
            {
                maxRadius = radius[i];
                maxCenter = i;
            }
        }
        
        delete [] radius;
        
        return s.substr((maxCenter - maxRadius - 1)/2, maxRadius);
    }
};