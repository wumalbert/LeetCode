class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *red = A, *white = A, *blue = A, *end = A+n;
        while (blue != end) {
            if (*blue == 2) {
                ++blue;
            } else if (*blue == 1) {
                *blue++ = 2;
                *white++ = 1;
            } else if (*blue == 0) {
                *blue++ = 2;
                *white++ = 1;
                *red++ = 0;
            }
        }
    }
};
class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *red = A, *white = A, *blue = A+n-1;
        while (white <= blue) {
            if (*white == 1) {
                ++white;
            } else if (*white == 0) {
                *white++ = 1;
                *red++ = 0;
            } else if (*white == 2) {
                *white = *blue;
                *blue-- = 2;
            }
        }
    }
};