class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = n-1;
        while (left <= right) {
            int middle = left + (right-left >> 1);
            if (A[middle] == target) return middle;
            if (A[middle] >= A[left]) { // the left part is sorted
                if (target < A[middle] && target >= A[left]) right = middle - 1;
                else left = middle + 1;
            } else {
                if (target > A[middle] && target <= A[right]) left = middle + 1;
                else right = middle - 1;
            }
        }
        return -1;
    }
};