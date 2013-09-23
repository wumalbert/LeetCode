class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int f0 = 1;
        int f1 = 1;
    
        for (int i = 2; i <= n; ++i)
        {
            int f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
        
        return f1;
    }
};