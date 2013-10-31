class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return dfs(s, 0, dict);
    }
private:
    bool dfs(const string &s, int index, const unordered_set<string> &dict) {
        if (s.length() == index) return true;
        for (int i = index; i < s.length(); ++i) {
            if (dict.find(s.substr(index, i-index+1)) != dict.end() && dfs(s, i+1, dict))
                return true;
        }
        return false;
    }
};
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        vector<bool> can_break(len+1, false);
        can_break[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (can_break[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    can_break[i] = true;
                    break;
                }
            }
        }
        return can_break[len];
    }
};