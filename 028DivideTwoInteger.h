class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        // 1. convert the numbers to positive number
        long long a = dividend, b = divisor;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long long bPreserve = b;
        while (b <= a) {
            int count = 0;
            while (b <= a) {
                if (0 == count) count = 1;
                else count <<= 1;
                b += b;
            }
            ret += count;
            a -= b >> 1;
            b = bPreserve;
        }
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) 
            ret = -ret;
        return ret;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        // 1. convert the numbers to positive number
        bool sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        unsigned a = dividend, b = divisor;
        if (dividend < 0) a = ~a+1;
        if (divisor < 0) b = ~b+1;
        unsigned base = 1;
        while (a>>1 >= b) {
            b <<= 1;
            base <<= 1;
        }
        while (base) {
            if (a >= b) {
                ret |= base;
                a -= b;
            }
            b >>= 1;
            base >>= 1;
        }
        return sign ? -ret : ret;
    }
};