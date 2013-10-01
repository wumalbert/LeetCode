class Solution {
private:
    int merge(map<int, int> &indexLens, int left, int right)
    {
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
        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
        {
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