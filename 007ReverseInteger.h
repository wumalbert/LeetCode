class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int isNeg = false;
        if (x < 0)
        {
            isNeg = true;
            x = -x;
        }
        
        int result = 0;
        int quotient = x;
        
        while(0 != quotient / 10)
        {
            result += quotient % 10;
            quotient = quotient / 10;
            result *= 10;
        }
        result += quotient;
        
        return isNeg ? -result : result;
    }
};