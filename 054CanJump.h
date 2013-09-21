class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int reach = 0;
        
        for (int i = 0; i <= reach && reach < n-1; ++i)
        {
            reach = max(reach, A[i]+i);
        }
        
        return reach >= n-1;
    }
};