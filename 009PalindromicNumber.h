class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        //convert the integer to another integer

        if (x < 0) return false;

        int old = x;

        int r = 0;
        while(x / 10 != 0)
        {
            r *= 10;
            r += x % 10;
            x = x / 10;
        }
        r *= 10;
        r += x % 10;

        if (r == old) return true;

        return false;
    }
};