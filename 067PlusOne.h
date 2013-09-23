class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        vector<int> ret(len+1, 0);
        
        ret[len] = (digits[len-1] + 1) % 10;
        int carry = (digits[len-1] + 1) / 10;
        for (int i = len-1; i > 0; --i)
        {
            int t = digits[i-1] + carry;
            ret[i] = t % 10;
            carry = t / 10;
        }
        ret[0] = carry;
        
        if (0 == ret[0]) ret.erase(ret.begin());
        
        return ret;
    }
};