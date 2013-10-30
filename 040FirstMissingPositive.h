class Solution {
private:
    void swap(int &a, int &b) {
        if (a != b) {
            a = a^b;
            b = a^b;
            a = a^b;
        }
    }
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0 && A[i] != i+1 && A[i] <= n && A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
                --i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i+1) return i+1;
        }
        return n+1;
    }
};