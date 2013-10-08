class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return 0;
        int sum = A[0], maxSum = A[0];
        for (int i = 1; i < n; ++i) {
            if (sum < 0) sum = A[i];
            else sum += A[i];
            if (sum > maxSum) maxSum = sum;
        }
        return maxSum;
    }
};