#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;
class Solution01 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count = 0;
        vector<string> words;
        map<string, int> ids;
        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
            words.push_back(*i);
            ids[*i] = count++;
        }
        if (dict.find(start) == dict.end()) {
            words.push_back(start);
            ids[start] = count++;
        }
        if (dict.find(end) == dict.end()) {
            words.push_back(end);
            ids[end] = count++;
        }
        vector<int> visit_level(words.size(), -1);
        vector<vector<int> > previsited(words.size(), vector<int>());
        queue<int> visit_queue;
        int number_current_level = 1, number_next_level = 0, level = 0;
        visit_queue.push(ids[start]);
        visit_level[ids[start]] = level++;
        while (!visit_queue.empty()) {
            int index = visit_queue.front();
            visit_queue.pop();
            --number_current_level;
            if (words[index] == end) break;
            for (int i = words[index].size()-1; i >= 0; --i) {
                string s = words[index];
                for (char c = 'a'; c <= 'z'; ++c) {
                    s[i] = c;
                    if (dict.find(s) == dict.end()) continue;
                    int t = ids[s];
                    if (-1 == visit_level[t]) {
                        visit_level[t] = level;
                        previsited[t].push_back(index);
                        visit_queue.push(t);
                        ++number_next_level;
                    } else if (visit_level[t] == level) {
                        previsited[t].push_back(index);
                    }
                }
            }
            if (0 == number_current_level) {
                number_current_level = number_next_level;
                number_next_level = 0;
                ++level;
            }
        }
        vector<vector<string> > ret;
        if (!previsited[ids[end]].empty()) {
            ret.push_back(vector<string>(1, end));
            while (!previsited[ids[ret[0][0]]].empty()) {
                for (int i = ret.size()-1; i >= 0; --i) {
                    int t = ids[ret[i][0]];
                    ret[i].insert(ret[i].begin(), words[previsited[t][0]]);
                    for (int j = previsited[t].size()-1; j > 0; --j) {
                        ret.push_back(ret[i]);
                        ret[ret.size()-1][0] = words[previsited[t][j]];
                    }
                }
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_set<string> visited;
        vector<string> word_ladder;
        vector<vector<string>> word_ladder_list;
        int shortest_path = numeric_limits<int>::max();
        dfs(start, end, dict, word_ladder, word_ladder_list, visited, 0, shortest_path);
        return word_ladder_list;
    }
private:
    void dfs(string &start, string &end, unordered_set<string> &dict, 
            vector<string> &word_ladder, vector<vector<string> > &word_ladder_list, 
            unordered_set<string> &visited, int path, int &shortest_path) {
        if (path > shortest_path) return;
        visited.insert(start);
        word_ladder.push_back(start);
        if (start == end) {
            if (path < shortest_path) {
                word_ladder_list.clear();
                word_ladder_list.push_back(word_ladder);
                shortest_path = path;
            } else if (path == shortest_path) {
                word_ladder_list.push_back(word_ladder);
            }
        } else {
            for (int i = 0; i < start.size(); ++i) {
                string s(start);
                for (char c = 'a'; c <= 'z'; ++c) {
                    s[i] = c;
                    if (dict.find(s) != dict.end() && visited.find(s) == visited.end()) {
                        dfs(s, end, dict, word_ladder, word_ladder_list, visited, path+1, shortest_path);
                    }
                }
            }
        }
        visited.erase(start);
        word_ladder.pop_back();
    }
};