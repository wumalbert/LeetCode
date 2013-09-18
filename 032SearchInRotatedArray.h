class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;

        while (left <= right)
        {
            int middle = left + (right-left)/2;

            if (A[middle] == target) return middle;

            if (A[left] <= A[middle]) // the left part is sorted
            {
                if (target >= A[left] && target < A[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else // the right part is sorted
            {
                if (target > A[middle] && target <= A[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return -1;
    }
};