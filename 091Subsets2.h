class Solution03 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> current;
        dfs(S, 0, current, ret);
        return ret;
    }
private:
    void dfs(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &ans) {
        if (S.size() == index) {
            ans.push_back(current);
            return;
        }
        int i;
        for (i = index+1; i < S.size() && S[i] == S[index]; ++i) {}
        for (int j = index; j <= i; ++j) {
            current.insert(current.end(), S.begin()+index, S.begin()+j);
            dfs(S, i, current, ans);
            current.erase(current.end()-(j-index), current.end());
        }
    }
};

class Solution02 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret(1, vector<int>());
        int i = 0;
        while (i < S.size()) {
            int j = i+1;
            while (j < S.size() && S[j] == S[i]) ++j;
            for (int k = ret.size()-1; k >= 0; --k) {
                for (int m = i+1; m <= j; ++m) {
                    ret.push_back(ret[k]);
                    ret.back().insert(ret.back().end(), S.begin()+i, S.begin()+m);
                }
            }
            i = j;
        }
        return ret;
    }
};

class Solution01 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> current;
        dfs(S, 0, current, ret);
        return ret;
    }
private:
    void dfs(vector<int> &S, int begin, vector<int> &current, vector<vector<int> > &ans) {
        ans.push_back(current);
        
        for (int i = begin; i < S.size(); ++i) {
            if (i > begin && S[i] == S[i-1]) continue;
            current.push_back(S[i]);
            dfs(S, i+1, current, ans);
            current.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > ret(1, vector<int>());
        int start = 0;
        for (int i = 0; i < S.size(); ++i) {
            int end = ret.size();
            for (int j = start; j < end; ++j) {
                ret.push_back(ret[j]);
                ret.back().push_back(S[i]);
            }
            if (i < S.size() && S[i+1] == S[i]) start = end;
            else start = 0;
        }
        return ret;
    }
};