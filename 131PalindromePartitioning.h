class Solution {
private:
    void DFS(const string s, const vector<vector<bool> > &palindromed, int index, vector<string> path, vector<vector<string> > &ans)
    {
        if (index == palindromed.size())
        {
            ans.push_back(path);
            return;
        }
        
        for (int i = index; i < palindromed.size(); ++i)
        {
            if (palindromed[index][i])
            {
                vector<string> par(path);
                par.push_back(s.substr(index, i-index+1));
                DFS(s, palindromed, i+1, par, ans);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        if (s.empty()) return ret;
        
        int len = s.length();
        vector<vector<bool> > palindromed(len, vector<bool>(len, false));
        
        for (int i = 0; i < len; ++i) palindromed[i][i] = true;
        for (int i = 0; i < len-1; ++i) palindromed[i][i+1] = (s[i] == s[i+1]);
        
        for (int i = 2; i < len; ++i)
            for (int j = 0; j < len-i; ++j)
                if (s[j] != s[j+i]) palindromed[j][j+i] = false;
                else palindromed[j][j+i] = palindromed[j+1][j+i-1];
        
        vector<string> path;
        DFS(s, palindromed, 0, path, ret);
        
        return ret;
    }
};