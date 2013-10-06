class Solution01 {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int s = (m+n) >> 1;
        if ((m+n) & 0x1) return solve(A, m, B, n, s + 1);
        else return 0.5 * (solve(A, m, B, n, s) + solve(A, m, B, n, s+1));
    }
private:
    double solve(int A[], int m, int B[], int n, int k) {
        if (m > n) return solve(B, n, A, m, k);
        if (0 == m) return B[k-1];
        if (1 == k) return min(A[0], B[0]);
        int k1 = min(k >> 1, m), k2 = k - k1;
        if (A[k1-1] < B[k2-1]) return solve(A+k1, m-k1, B, n, k2);
        else if(A[k1-1] > B[k2-1]) return solve(A, m, B+k2, n-k2, k1);
        else return A[k1-1];
    }
};
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int k = m + ((n-m)>>1); // find the Kth element (index from 1)
        if ((m+n) & 0x1) ++k; 
        int left_A = 0, right_A = m-1, left_B = 0, right_B = n-1;
        int first = 0;
        while (k && left_A <= right_A && left_B <= right_B) {
            if (1 == k) {
                if (A[left_A] <= B[left_B]) {
                    first = A[left_A];
                    left_A += 1;
                } else if (A[left_A] > B[left_B]) {
                    first = B[left_B];
                    left_B += 1;
                }
                k = 0;
                break;
            }
            int k1 = min(k >> 1, right_A - left_A + 1), k2 = k - k1;
            if (k2 > right_B - left_B + 1) {
                k2 = right_B - left_B + 1;
                k1 = k - k2;
            }
            if (A[left_A + k1 - 1] > B[left_B + k2 - 1]) {
                left_B += k2;
                k = k1;
            } else if (A[left_A + k1 - 1] < B[left_B + k2 -1]) {
                left_A += k1;
                k = k2;
            } else if (A[left_A + k1 - 1] == B[left_B + k2 - 1]) {
                first = A[left_A + k1 - 1];
                left_A += k1;
                left_B += k2;
                k = 0;
            }
        }
        if (k > 0) {
            if (left_A > right_A) {
                first = B[left_B + k - 1];
                left_B += k;
            } else if (left_B > right_B) {
                first = A[left_A + k - 1];
                left_A += k;
            }
            k = 0;
        }
        if ((m+n) & 0x1) return static_cast<double>(first);
        int second = numeric_limits<int>::max();
        if (left_A <= right_A && A[left_A] < second) second = A[left_A];
        if (left_B <= right_B && B[left_B] < second) second = B[left_B];
        return 0.5 * (first + second);
    }
};