class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > 0 && A[i] < n)
            {
                int t = A[i]-1;
                if (t != i && A[t] != A[i])
                {
                    A[t] = A[t] ^ A[i];
                    A[i] = A[t] ^ A[i];
                    A[t] = A[t] ^ A[i];
                    --i;
                }
            }
            
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != i+1) return i+1;
        }
        return n+1;
    }
};