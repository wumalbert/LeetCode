class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> symbol(n, 1);
        vector<int> base(n, 1);
        for (int i = n-2, j = 1; i >= 0; --i, ++j) {
            base[i] = j * base[i+1];
            symbol[j-1] = '0' + j;
        }
        symbol[n-1] = '0' + n;
        string ret(n, ' ');
        --k;
        for (int i = 0; i < n; ++i) {
            int t = k / base[i];
            ret[i] = symbol[t];
            k -= base[i]*t;
            symbol.erase(symbol.begin()+t);
        }
        return ret;
    }
};