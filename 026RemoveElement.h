class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *begin = A, *end = A+n, *top = A;
        while (begin != end) {
            if (*begin != elem) *top++ = *begin;
            ++begin;
        }
        return top-A;
    }
};