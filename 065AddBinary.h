class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ret("");
        int carry = 0;
        string::iterator ita = a.end()-1, itb = b.end()-1;
        while (ita >= a.begin() || itb >= b.begin() || carry) {
            int t = carry;
            if (ita >= a.begin()) {
                t += *ita - '0';
                --ita;
            }
            if (itb >= b.begin()) {
                t += *itb - '0';
                --itb;
            }
            ret = static_cast<char>('0' + (t % 2)) + ret;
            carry = t / 2;
        }
        return ret;
    }
};