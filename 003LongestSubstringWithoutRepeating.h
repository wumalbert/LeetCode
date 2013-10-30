class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> location(256, -1);
        int count = 0, longest = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (location[s[i]] < start) {
                ++count;
                location[s[i]] = i;
            } else {
                if (count > longest) longest = count;
                start = location[s[i]] + 1;
                count = i - start + 1;
                location[s[i]] = i;
            }
        }
        if (count > longest) longest = count;
        return longest;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<char, int> last_index_map;
        int count = 0, longest = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (last_index_map.find(s[i]) == last_index_map.end() || last_index_map[s[i]] < start) {
                ++count;
                last_index_map[s[i]] = i;
            } else {
                if (count > longest) longest = count;
                start = last_index_map[s[i]] + 1;
                count = i - start + 1;
                last_index_map[s[i]] = i;
            }
        }
        if (count > longest) longest = count;
        return longest;
    }
};