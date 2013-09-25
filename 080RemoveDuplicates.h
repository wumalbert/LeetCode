class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!A) return 0;
        if (n <= 2) return n;
        
        static const int kDuplicate = 2;
        
        int count = 1;
        int last = A[0];
        int *pStart = A+1, *pEnd = A + n, *pTail = A;
        while (pStart != pEnd)
        {
            if (*pStart == last) ++count;
            else
            {
                count = 1;
                last = *pStart;
            }
            
            if (count <= kDuplicate) *(++pTail) = *pStart++;
            else ++pStart;
        }
        
        return pTail - A + 1;
    }
};