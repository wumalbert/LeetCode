class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == n) return 0;

        int *pResult = A;
        int *pBegin = A;
        int *pEnd = A+n;

        while (pBegin < pEnd)
        {
            if (*pBegin == elem)
            {
                ++pBegin;
            }
            else
            {
                *pResult++ = *pBegin++;
            }
        }
        return pResult - A;
    }
};