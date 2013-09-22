class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const static int p[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        
        if (k < 1 || k > p[n]) return "";
        
        int kk = k-1;
        vector<int> index(n, 0);
        for (int i = n-1; i >= 0; --i)
        {
            while (kk >= p[i])
            {
                ++index[i];
                kk -= p[i];
            }
        }
        
        vector<int> num(n, 0);
        for (int i =0; i < n; ++i)
            num[i] = i+1;
        
        string ret;
        for (int i = n-1; i >= 0; --i)
        {
            ret += num[index[i]] + '0';
            num.erase(num.begin() + index[i]);
        }
        
        return ret;
    }
};