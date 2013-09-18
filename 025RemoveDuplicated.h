class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == n) return 0;

        int* pUnique = A+1;
        int* pBegin = A+1;
        int* pEnd = A+n;

        while (pBegin < pEnd)
        {
            if (*pBegin == *(pBegin-1))
            {
                ++pBegin;
            }
            else
            {
                *pUnique++ = *pBegin++;
            }
        }

        return pUnique-A;
    }
};