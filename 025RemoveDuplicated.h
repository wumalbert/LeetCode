class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == n) return 0;
        int *pUnique = A+1, *pBegin = A+1, *pEnd = A+n;
        while (pBegin < pEnd) {
            if (*pBegin == *(pBegin-1)) {
                ++pBegin;
            } else {
                *pUnique++ = *pBegin++;
            }
        }
        return pUnique-A;
    }
};
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return unique(A, A+n) - A;
    }
};