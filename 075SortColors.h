class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *pRed, *pWhite, *pBlue;
        pRed = pWhite = A-1;
        pBlue = A;
        int *pEnd = A + n;
        while (pBlue != pEnd)
        {
            if (2 == *pBlue)
            {
                ++pBlue;
            }
            else if (1 == *pBlue)
            {
                *pBlue++ = 2;
                *(++pWhite) = 1;
            }
            else if (0 == *pBlue)
            {
                *pBlue++ = 2;
                *(++pWhite) = 1;
                *(++pRed) = 0;
            }
        }
    }
};