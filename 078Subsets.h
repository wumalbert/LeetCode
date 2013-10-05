class Solution02 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> current;
        subsetsRecursive(S, 0, current, ret);
        return ret;
    }
private:
    void subsetsRecursive(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &ans) {
        if (S.size() == index) {
            ans.push_back(current);
            return;
        }
        subsetsRecursive(S, index+1, current, ans);
        current.push_back(S[index]);
        subsetsRecursive(S, index+1, current, ans);
        current.pop_back();
    }
};

class Solution01 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        int n = S.size();
        for (int i = (1 << n) - 1; i >= 0; --i) {
            vector<int> current;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) current.push_back(S[j]);
            }
            ret.push_back(current);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret(1, vector<int>());
        for (vector<int>::iterator i = S.begin(); i != S.end(); ++i) {
            for (int j = ret.size()-1; j >= 0; --j) {
                ret.push_back(ret[j]);
                ret.back().push_back(*i);
            }
        }
        return ret;
    }
};