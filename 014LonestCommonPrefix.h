class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); ++i) {
            if (!isEqual(strs, i, 0, strs.size()-1))
                return strs[0].substr(0, i);
        }
        return strs[0];
    }
private:
    bool isEqual(vector<string> &strs, int index, int start, int end) {
        if (start > end) return true;
        if (start == end) {
            if (strs[start].size() <= index) return false;
            else return true;
        }
        int middle = start + (end - start >> 1);
        bool left = isEqual(strs, index, start, middle);
        bool right = isEqual(strs, index, middle+1, end);
        if (!left || !right || strs[start].size() <= index || strs[end].size() <= index || 
            strs[start][index] != strs[end][index]) 
            return false;
        return true;
    }
};