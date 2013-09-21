class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == n) return 1;
        if (1 == n) return x;
        
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        
        double r = pow(x, n/2);
        
        if (n&0x1) return r * r * x;
        
        return r*r;
    }
};