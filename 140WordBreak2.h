#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution01 {    
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        vector<vector<int> > prewords(len+1, vector<int>());
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((j == 0 || !prewords[j].empty()) && dict.find(s.substr(j, i-j)) != dict.end())
                    prewords[i].push_back(j);
            }
        }
        vector<string> ret;
        if (prewords[len].empty()) return ret;
        vector<vector<int> > word_break_index(1, vector<int>(1, len));
        bool flag = true;
        while(flag) {
            flag = false;
            int size = word_break_index.size();
            for (int i = size-1; i >= 0; --i) {
                int t = word_break_index[i][0];
                if (0 == t) continue;
                flag = true;
                word_break_index[i].insert(word_break_index[i].begin(), prewords[t][0]);
                vector<int> path(word_break_index[i]);
                for (int j = 1; j < prewords[t].size(); ++j) {
                    path[0] = prewords[t][j];
                    word_break_index.push_back(path);
                }
            }
        }
        for (vector<vector<int> >::const_iterator i = word_break_index.begin(); i != word_break_index.end(); ++i) {
            string word;
            for (vector<int>::const_iterator j = i->begin()+1; j != i->end(); ++j) {
                word += s.substr(*(j-1), *j - *(j-1)) + " ";
            }
            ret.push_back(word.substr(0, word.size()-1));
        }
        return ret;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        vector<vector<int> > prewords(len+1, vector<int>());
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((j == 0 || !prewords[j].empty()) && dict.find(s.substr(j, i-j)) != dict.end())
                    prewords[i].push_back(j);
            }
        }
        vector<string> ret;
        string word;
        dfs(s, prewords, len, word, ret);
        return ret;
    }
private:
    void dfs(const string &s, const vector<vector<int> > &prewords, int index, string &word, vector<string> &ans) {
        if (0 == index) {
            ans.push_back(word.substr(0, word.size()-1));
        } else {
            for (vector<int>::const_iterator i = prewords[index].begin(); i != prewords[index].end(); ++i) {
                word = s.substr(*i, index-*i) + " " + word;
                dfs(s, prewords, *i, word, ans);
                word = word.substr(index-*i+1);
            }
        }
    }
};