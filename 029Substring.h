#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool match(string& s, size_t start, vector<string> &L) {
        vector<bool> flag(L.size(), false);
        size_t m = L[0].length();
        size_t end = start + L.size() * m;
        for (size_t i = start; i < end; i += m) {
            string sub = s.substr(i, m);
            size_t j;
            for (j = 0; j < L.size(); ++j) {   
                if (!flag[j] && sub == L[j])  {
                    flag[j] = true;
                    break;
                }
            }
            if (j >= L.size()) return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (L.empty()) return ret;
        int m = L.size() * L[0].length();
        for (int i = 0; i <= S.length() - m; ++i) {
            if (match(S, i, L)) ret.push_back(i);
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (L.empty()) return ret;
        int m = S.length(), n = L.size(), len = L[0].length();
        if (m < n*len) return ret;
        // map the string in L to index
        map<string, int> word_index_map;
        vector<int> required(n, 0);
        for (int i = 0; i < L.size(); ++i)
        {
            if (word_index_map.find(L[i]) == word_index_map.end())
                word_index_map[L[i]] = i;
            ++required[word_index_map[L[i]]];
        }
        // search every substr in S
        vector<int> sids(m, -1);
        for (int i = 0; i <= m-len; ++i) {
            string s = S.substr(i, len);
            if (word_index_map.find(s) != word_index_map.end())
                sids[i] = word_index_map[s];
        }
        // find the substring with concatenation of all words in L 
        for (int offset = 0; offset < len; ++offset) {
            vector<int> found(n, 0);
            int count = 0, begin = offset;
            for (int i = begin; i <= m-len; i += len) {
                if (-1 == sids[i]) { // there is no map in the current window
                    count = 0;
                    for (vector<int>::iterator it = found.begin(); it != found.end(); ++it)
                        *it = 0;
                    begin = i + len;
                } else {
                    int id = sids[i];
                    ++found[id];
                    if (required[id] >= found[id]) {
                        ++count;
                        if (count == n) ret.push_back(begin);
                    }
                    if ((i - begin) / len + 1 == n) {
                        id = sids[begin];
                        if (required[id] >= found[id])
                            --count;
                        --found[id];
                        begin += len;
                    }
                }
            }
        }
        return ret;
    }
};