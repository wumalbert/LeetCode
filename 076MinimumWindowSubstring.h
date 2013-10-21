class Solution {
public:
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<char, int> required, founded;
        for (string::iterator i = T.begin(); i != T.end(); ++i) ++required[*i];
        int min_window_start = -1, min_window_length = S.length()+1, count = 0;
        for (string::iterator start = S.begin(), current = S.begin(); current != S.end(); ++current) {
            if (required.find(*current) == required.end()) continue;
            ++founded[*current];
            if (founded[*current] <= required[*current]) {
                ++count;
                if (count == T.length()) {
                    while (start < current) {
                        if (required.find(*start) == required.end()) ++start;
                        else if (founded[*start] > required[*start]) --founded[*start++];
                        else break;
                    }
                    if (current - start + 1 < min_window_length) {
                        min_window_start = start - S.begin();
                        min_window_length = current - start + 1;
                    }
                    --founded[*start++];
                    --count;
                }
            }
        }
        if (min_window_start < 0) return "";
        else return S.substr(min_window_start, min_window_length);
    }
};