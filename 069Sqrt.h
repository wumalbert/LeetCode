class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x < 0) return -1;
        int left = 0, right = x;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            long long t = static_cast<long long>(middle) * middle;
            if (t == x) return middle;
            else if (t < x) left = middle+1;
            else right = middle-1;
        }
        return right;
    }
};