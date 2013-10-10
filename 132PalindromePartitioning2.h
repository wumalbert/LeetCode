class Solution {
public:
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return 0;
        int len = s.length();
        vector<vector<bool> > palindromed(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) palindromed[i][i] = true;
        for (int i = 0; i < len-1; ++i) palindromed[i][i+1] = s[i] == s[i+1];
        for (int i = 2; i < len; ++i)
            for (int j = 0; j < len-i; ++j)
                if (s[j] != s[j+i]) palindromed[j][j+i] = false;
                else palindromed[j][j+i] = palindromed[j+1][j+i-1];
        // BFS, from start to the end
        vector<int> levels(len, -1);
        queue<int> path_queue;
        path_queue.push(0);
        int level0 = 1, level1 = 0, level = 0;
        while (!path_queue.empty()) {
            int current = path_queue.front();
            path_queue.pop();
            --level0;
            for (int i = current; i < len; ++i) {
                if (palindromed[current][i] && -1 == levels[i]) {
                    if (i == len-1) return level;
                    levels[i] = level;
                    path_queue.push(i+1);
                    ++level1;
                }
            }
            if (0 == level0) {
                ++level;
                level0 = level1;
                level1 = 0;
            }
        }
    }
};
class Solution {
public:
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return 0;
        int len = s.length();
        vector<vector<bool> > palindromed(len, vector<bool>(len, false));
        vector<int> cut(len+1, 0);
        cut[len] = -1;
        for (int i = len-1; i >= 0; --i) {
            cut[i] = len-1-i;
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j-i < 2 || palindromed[i+1][j-1])) {
                    palindromed[i][j] = true;
                    cut[i] = min(cut[i], cut[j+1]+1);
                }
            }
        }
        return cut[0];
    }
};