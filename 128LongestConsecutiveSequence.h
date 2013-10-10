#include <vector>
#include <map>
using namespace std;

class Solution01 {
private:
    int merge(map<int, int> &indexLens, int left, int right) {
        int lower = left - indexLens[left] + 1;
        int upper = right + indexLens[right] - 1;
        int len = upper - lower + 1;
        indexLens[lower] = len;
        indexLens[upper] = len;
        return len;
    }
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> indexLens;
        int longest = 1;
        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
            if (indexLens.find(*it) != indexLens.end()) continue;
            indexLens[*it] = 1;
            if (indexLens.find(*it-1) != indexLens.end())
                longest = max(longest, merge(indexLens, *it-1, *it));
            if (indexLens.find(*it+1) != indexLens.end())
                longest = max(longest, merge(indexLens, *it, *it+1));
        }
        return longest;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int, int> sequence_map;
        int max_length = numeric_limits<int>::min();
        for (int i = 0; i < num.size(); ++i) {
            if (sequence_map.find(num[i]) != sequence_map.end()) continue;
            sequence_map[num[i]] = 1;
            bool left_existed = sequence_map.find(num[i]-1) != sequence_map.end();
            bool right_existed = sequence_map.find(num[i]+1) != sequence_map.end();
            int left = num[i], right = num[i];
            if (left_existed && right_existed) {
                left = num[i] - sequence_map[num[i]-1];
                right = num[i] + sequence_map[num[i]+1];
            } else if (left_existed) {
                left = num[i] - sequence_map[num[i]-1];
            } else if (right_existed) {
                right = num[i] + sequence_map[num[i]+1];
            }
            int len = right - left + 1;
            sequence_map[left] = sequence_map[right] = len;
            if (len > max_length) max_length = len;
        }
        return max_length;
    }
};