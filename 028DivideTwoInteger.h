class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int ret = 0;

        // 1. convert the numbers to positive number
        double a = dividend;
        double b = divisor;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        double bPrev = b;
        double bPreserve = b;
        while (b <= a)
        {
            int count = 0;
            while (b <= a)
            {
                if (0 == count) count = 1;
                else count <<= 1;

                bPrev = b;
                b += b;
            }
            ret += count;

            a -= bPrev;
            b = bPreserve;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) 
            return -ret;
        return ret;
    }
};