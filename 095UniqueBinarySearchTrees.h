class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> nBST(n+1, 1);
        
        for (int i = 2; i <= n; ++i)
        {
            nBST[i] = 0;
            for (int j = 1; j <= i; ++j)
            {
                nBST[i] += nBST[j-1]*nBST[i-j];
            }
        }
        
        return nBST[n];
    }
};