class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        if (y > numeric_limits<int>::max()) return numeric_limits<int>::max();
        else if (y < numeric_limits<int>::min()) return numeric_limits<int>::min();
        else return y;
    }
};