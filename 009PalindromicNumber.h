class Solution01 {
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
class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x < 0) return false;
        int high = 1;
        for (int y = x/10; y / high != 0; high *= 10) {}
        while (x / 10) {
            if (x / high != x % 10) return false;
            x = (x % high) / 10;
            high /= 100;
        }
        return true;
    }
};