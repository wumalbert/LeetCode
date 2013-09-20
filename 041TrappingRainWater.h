class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int maxIndex = 0;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] > A[maxIndex])
                maxIndex = i;
        }
        
        int height = 0, water = 0;
        for (int i = 0; i < maxIndex; ++i)
        {
            if (height > A[i])
                water += height - A[i];
            else height = A[i];
        }
        
        height = 0;
        for (int i = n-1; i > maxIndex; --i)
        {
            if (height > A[i])
                water += height - A[i];
            else height = A[i];
        }
        
        return water;
    }
};