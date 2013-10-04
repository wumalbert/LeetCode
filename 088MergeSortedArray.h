class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *pa = A+m-1, *pb = B+n-1, *pd = A+m+n-1;
        while (pa >= A && pb >= B) {
            *pd-- = *pa > *pb ? *pa-- : *pb--;
        }
        if (pa < A) {
            while (pb >= B) *pd-- = *pb--;
        }
    }
};