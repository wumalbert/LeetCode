class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count = 0, longest = 0, last = -1, left_paren = 0;
        stack<int> left_pos;
        for (int i = 0; i < s.length(); ++i) {
            if ('(' == s[i]) {
                left_pos.push(i);
            } else {
                if (left_pos.empty()) {
                    last = i;
                } else {
                    left_pos.pop();
                    if (left_pos.empty()) longest = max(longest, i-last);
                    else longest = max(longest, i-left_pos.top());
                }
            }
        }
        return longest;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return max(helper(s.begin(), s.end(), '('), helper(s.rbegin(), s.rend(), ')'));
    }
private:
    template<class Iter>
    int helper(Iter begin, Iter end, const char left) {
        int longest = 0, opened = 0;
        string::iterator last = begin-1;
        while (begin != end) {
            opened += *begin == '(' ? 1 : -1;
            if (opened == 0) {
                longest = max(longest, begin - last);
            } else if (opened < 0) {
                opened = 0;
                last = begin;
            }
            ++begin;
        }
        return longest;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length(), longest = 0;
        vector<int> parentheses(len+1, 0);
        for (int i = 1; i <= len; ++i) {
            if (s[i-1] == '(') {
                parentheses[i] = 0;
            } else if (i >= 2){
                if (s[i-2] == '(') {
                    parentheses[i] = 2 + parentheses[i-2];
                } else {
                    int t = i-parentheses[i-1]-2;
                    if (t >= 0 && s[t] == '(') 
                        parentheses[i] = 2 + parentheses[i-1] + parentheses[t];
                }
                if (parentheses[i] > longest) longest = parentheses[i];
            }
        }
        return longest;
    }
};