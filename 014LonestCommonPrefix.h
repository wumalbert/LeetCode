class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        size_t i = 0;
        while (true)
        {
            if (i >= strs[0].length()) strs[0].substr(0, i);

            char t = strs[0][i];

            for (size_t j = 1; j < strs.size(); ++j)
            {
                if (i >= strs[j].length() || strs[j][i] != t)
                    return strs[j].substr(0, i);
            }

            ++i;
        }
        return strs[0].substr(0, i);
    }
};