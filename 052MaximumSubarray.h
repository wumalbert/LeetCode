class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!A || 0 == n) return 0;
        
        vector<int> maxSum(n, numeric_limits<int>::min());
        
        maxSum[0] = A[0];
        
        int ret = maxSum[0];
        
        for (int i = 1; i < n; ++i)
        {
            maxSum[i] = maxSum[i-1] < 0 ? A[i] : maxSum[i-1]+A[i];
            
            if (maxSum[i] > ret) ret = maxSum[i];
        }
        
        return ret;
    }
};