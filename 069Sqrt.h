class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x < 0) return -1;
        if (0 == x) return 0;
        int left = 1, right = x;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            if (middle == x/middle) return middle;
            else if (middle < x/middle) left = middle+1;
            else right = middle-1;
        }
        return right;
    }
};