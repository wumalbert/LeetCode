class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = digits.size();
        vector<int> ret(len+1, 0);
        ret[len] = (digits[len-1] + 1) % 10;
        int carry = (digits[len-1] + 1) / 10;
        for (int i = len-1; i > 0; --i) {
            int t = digits[i-1] + carry;
            ret[i] = t % 10;
            carry = t / 10;
        }
        ret[0] = carry;
        if (0 == ret[0]) ret.erase(ret.begin());
        return ret;
    }
};