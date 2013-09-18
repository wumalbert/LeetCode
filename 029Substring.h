#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool match(string& s, size_t start, vector<string> &L)
    {
        vector<bool> flag(L.size(), false);

        size_t m = L[0].length();
        size_t end = start + L.size() * m;
        for (size_t i = start; i < end; i += m)
        {
            string sub = s.substr(i, m);
            size_t j;
            for (j = 0; j < L.size(); ++j)
            {   
                if (!flag[j] && sub == L[j]) 
                {
                    flag[j] = true;
                    break;
                }
            }
            if (j >= L.size()) return false;
        }
        return true;
    }

public:
    vector<int> findSubstringBF(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // build a trie tree L
        vector<int> ret;

        if (L.empty()) return ret;

        size_t m = L.size() * L[0].length();

        for (size_t i = 0; i <= S.length() - m; ++i)
        {
            if (match(S, i, L)) ret.push_back(i);
        }

        return ret;
    }

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> ret;

        if (L.empty()) return ret;

        int m = S.length();
        int n = L.size();
        int len = L[0].length();

        if (m < n*len) return ret;

        // map the string in L to index
        map<string, int> wordIds;
        vector<int> need(n, 0);
        for (int i = 0; i < L.size(); ++i)
        {
            int index;
            if (!wordIds.count(L[i]))
            {
                wordIds[L[i]] = i;
                index = i;
            }
            else index = wordIds[L[i]];
            ++need[index];
        }

        // search every substr in S
        vector<int> sids(m, -1);
        for (int i = 0; i <= m-len; ++i)
        {
            string s = S.substr(i, len);
            if (wordIds.count(s))
                sids[i] = wordIds[s];
        }

        // find the substring with concatenation of all words in L 
        for (int offset = 0; offset < len; ++offset)
        {
            vector<int> found(n, 0);
            int count = 0;
            int begin = offset;
            for (int i = begin; i <= m-len; i += len)
            {
                if (-1 == sids[i]) // there is no map in the current window
                {
                    // clear the count and found vector
                    count = 0;
                    for (vector<int>::iterator it = found.begin(); it != found.end(); ++it)
                        *it = 0;

                    begin = i + len;
                }
                else
                {
                    int id = sids[i];
                    ++found[id];

                    if (need[id] >= found[id])
                        ++count;

                    if (count == n)
                    {
                        ret.push_back(begin);
                    }

                    if ((i - begin) / len + 1 == n)
                    {
                        id = sids[begin];
                        if (need[id] >= found[id])
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

