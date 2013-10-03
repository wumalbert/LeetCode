// recursive solution
class Solution01 {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return 1;
        else if (1 == n) return x;
        static const int kNegetiveMask = 0x80000000;
        bool negetive = n & kNegetiveMask;
        unsigned int m = n;
        double ret = pow(x, n>>1);
        if (n & 0x1) ret *= ret*x;
        else ret *= ret;
        return negetive ? 1/ret : ret; 
    }
};
// iteration solution
class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        static const int kNegetiveMask = 0x80000000;
        bool negetive = n & kNegetiveMask;
        unsigned int m = n;
        if (negetive) m = ~m + 1;
        double ret = 1;
        while (m) {
            if (m & 0x1) ret *= x;
            x *= x;
            m >>= 1;
        }
        return negetive ? 1/ret : ret;
    }
};