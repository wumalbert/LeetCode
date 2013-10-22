class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        solve(n, ret);
        return ret;
    }
private:
    void solve(int n, vector<int> &ans) {
        if (n == 0) {
            ans.push_back(0);
        } else {
            solve(n-1, ans);
            int t = 1 << (n-1);
            for (int i = ans.size()-1; i >= 0; --i) {
                ans.push_back(ans[i] + t);
            }
        }
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret(1, 0);
        for (int i = 1; i <= n; ++i) {
            int t = 1 << (i-1);
            for (int j = ret.size()-1; j >= 0; --j)
                ret.push_back(ret[j] + t);
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        int size = 1 << n;
        for (int i = 0; i < size; ++i) {
            ret.push_back(i ^ (i>>1));
        }
        return ret;
    }
};