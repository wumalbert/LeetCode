class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return 0;
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < n; ++i) {
            two |= one & A[i];
            one = one ^ A[i];
            three = ~(two & one);
            one &= three;
            two &= three;
        }
        return one;
    }
};
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return 0;
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 1 << i, count = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] & bit) ++count;
            }
            if (count % 3 != 0) ret |= bit;
        }
        return ret;
    }
};