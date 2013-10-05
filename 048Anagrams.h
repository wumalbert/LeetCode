class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<string, vector<string> > anagrams_map;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string key(*it);
            sort(key.begin(), key.end());
            anagrams_map[key].push_back(*it);
        }
        vector<string> ret;
        for (unordered_map<string, vector<string> >::iterator it = anagrams_map.begin(); it != anagrams_map.end(); ++it) {
            if (it->second.size() > 1) {
                ret.insert(ret.end(), it->second.begin(), it->second.end());
            }
        }
        return ret;
    }
};