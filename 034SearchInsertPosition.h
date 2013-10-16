class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A || 0 == n) return -1;
        int left = 0, right = n-1;
        while (left <= right) {
            int middle = left + (right-left >> 1);
            if (A[middle] == target) return middle;
            else if (A[middle] < target) left = middle + 1;
            else right = middle-1;
        }
        return left;
    }
};