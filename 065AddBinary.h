class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        int len1 = a.length();
        int len2 = b.length();
        int len = max(len1, len2) + 1;
        
        string ret(len, '0');
        int i = len1-1;
        int j = len2-1;
        int k = len-1;
        int carry = 0;
        while (k >= 0)
        {
            int t1 = i >= 0 ? a[i--]-'0' : 0;
            int t2 = j >= 0 ? b[j--]-'0' : 0;
            t1 = t1 + t2 + carry;
            ret[k--] += t1 % 2;
            carry = t1 / 2;
        }
        
        for (k = 0; k < len-1 && '0' == ret[k]; ++k);
        return ret.substr(k, len-k);
    }
};