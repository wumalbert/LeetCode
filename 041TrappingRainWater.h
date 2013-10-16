class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int max_index = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[max_index]) max_index = i;
        }
        int ret = 0, max_last = A[0];
        for (int i = 0; i < max_index; ++i) {
            if (A[i] >= max_last) {
                max_last = A[i];
            } else {
                ret += max_last - A[i];
            }
        }
        max_last = A[n-1];
        for (int i = n-1; i > max_index; --i) {
            if (A[i] >= max_last) {
                max_last = A[i];
            } else {
                ret += max_last - A[i];
            }
        }
        return ret;
    }
};
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0, left = 0, right = n-1;
        while (left < right) {
            if (A[left] <= A[right]) {
                int k = left + 1;
                while (A[k] < A[left]) {
                    ret += A[left] - A[k];
                    ++k;
                }
                left = k;
            } else {
                int k = right-1;
                while (A[k] < A[right]) {
                    ret += A[right] - A[k];
                    --k;
                }
                right = k;
            }
        }
        return ret;
    }
};
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n < 1) return 0;
        vector<int> left_max(n, A[0]), right_max(n, A[n-1]);
        for (int i = 1; i < n-1; ++i) {
            left_max[i] = max(left_max[i-1], A[i]);
            right_max[n-i-1] = max(right_max[n-i], A[n-i-1]);
        }
        left_max[n-1] = max(left_max[n-2], A[n-1]);
        right_max[0] = max(right_max[1], A[0]);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int height = min(left_max[i], right_max[i]);
            if (height > A[i]) ret += height - A[i];
        }
        return ret;
    }
};