class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A || 0 == n) return 0;
        static const int kDuplicate = 2;
        int count = 1, last = *A;
        int *pStart = A+1, *pEnd = A+n, *pTail = A+1;
        while (pStart != pEnd) {
            if (*pStart == last) {
                ++count;
            } else {
                count = 1;
                last = *pStart;
            }
            if (count <= kDuplicate) *pTail++ = *pStart++;
            else ++pStart;
        }
        return pTail - A;
    }
};
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A) return 0;
        if (n <= 2) return n;
        static const int kDuplicate = 2;
        int count = 1, last = *A;
        int *pStart = A+2, *pEnd = A+n, *pTail = A+2;
        while (pStart != pEnd) {
            if (*pStart != last) {
                last = *(pStart-1);
                *pTail++ = *pStart++;
            }
            else ++pStart;
        }
        return pTail - A;
    }
};