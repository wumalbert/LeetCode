class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int ret = 0;
        for (int i = 0; i < n; ++i) ret ^= A[i];
        return ret;
    }
};
class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for (int i = 1; i < n; ++i) A[0] ^= A[i];
        return A[0];
    }
};