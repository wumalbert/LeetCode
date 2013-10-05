class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > ret;
        if (s.empty()) return ret;
        int len = s.length();
        vector<vector<bool> > palindromed(len, vector<bool>(len, false));
        for (int i = 0; i < len-1; ++i) {
            palindromed[i][i] = true;
            palindromed[i][i+1] = s[i] == s[i+1];
        }
        palindromed[len-1][len-1] = true;
        for (int l = 2; l < len; ++l) {
            for (int i = 0; i < len-l; ++i) {
                palindromed[i][i+l] = s[i] == s[i+l] && palindromed[i+1][i+l-1];
            }
        }
        vector<string> par;
        dfs(s, palindromed, 0, par, ret);
        return ret;
    }
private:
    void dfs(const string &s, vector<vector<bool> > &palindromed, int index, vector<string> &par, vector<vector<string> > &ans) {
        if (s.length() == index) {
            ans.push_back(par);
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            if (palindromed[index][i]) {
                par.push_back(s.substr(index, i-index+1));
                dfs(s, palindromed, i+1, par, ans);
                par.pop_back();
            }
        }
    }
};