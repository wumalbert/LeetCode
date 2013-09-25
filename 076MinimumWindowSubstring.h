class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        static const int kChar = 256;
        vector<int> need(kChar, 0);
        
        for (int i = 0; i < T.length(); ++i)
            ++need[T[i]];
    
        vector<int> found(kChar, 0);
        int minWidth = numeric_limits<int>::max();
        int minStart = 0;
        int count = 0;
        for (int begin = 0, end = 0; end < S.length(); ++end)
        {
            char c = S[end];
            if (0 == need[c]) continue;
            
            ++found[c];
            
            if (found[c] <= need[c]) ++count;
            
            if (count == T.length())
            {
                while (0 == need[S[begin]] || found[S[begin]] > need[S[begin]])
                {
                    if (found[S[begin]] > need[S[begin]]) --found[S[begin]];
                    ++begin;
                }
                
                int window = end - begin + 1;
                if (window < minWidth)
                {
                    minWidth = window;
                    minStart = begin;
                }
            }
        }
        
        if (numeric_limits<int>::max() == minWidth) return "";
        return S.substr(minStart, minWidth);
    }
};