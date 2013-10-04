// Iterator
class Solution02 {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > all_parentheses;
        all_parentheses.push_back(vector<string>(1, ""));
        all_parentheses.push_back(vector<string>(1, "()"));
        for (int i = 2; i <= n; ++i) {
            vector<string> current_parentheses;
            for (int j = 0; j < i; ++j) {
                for (vector<string>::iterator it1 = all_parentheses[j].begin(); it1 != all_parentheses[j].end(); ++it1) {
                    for (vector<string>::iterator it2 = all_parentheses[i-j-1].begin(); it2 != all_parentheses[i-j-1].end(); ++it2) {
                        current_parentheses.push_back("("+*it1+")"+*it2);
                    }
                }
            }
            all_parentheses.push_back(current_parentheses);
        }
        return all_parentheses.back();
    }
};
// Recursive
class Solution01 {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s;
        vector<string> ret;
        generateParenthesis(n, 0, s, ret);
        return ret;
    }
private:
    void generateParenthesis(int to_open, int opened, string &s, vector<string> &ans) {
        if (to_open == 0 && opened == 0) {
            ans.push_back(s);
            return;
        }
        if (to_open > 0) {  // every positon have two choices, '(' or ')'
            s += '(';
            generateParenthesis(to_open-1, opened+1, s, ans);
            s.erase(s.end()-1, s.end());
        }
        if (opened > 0) { 
            s += ')';
            generateParenthesis(to_open, opened-1, s, ans);
            s.erase(s.end()-1, s.end());
        }
    }
};
// Recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s;
        vector<string> ret;
        generateParenthesis(n, 0, 0, s, ret);
        return ret;
    }
private:
    void generateParenthesis(int n, int left, int right, string &s, vector<string> &ans) {
        if (left == n) {
            ans.push_back(s.append(n-right, ')'));
            s.erase(s.end()-(n-right), s.end());
            return;
        }
        // every positon have two choices, '(' or ')'
        s += '(';
        generateParenthesis(n, left+1, right, s, ans);
        s.erase(s.end()-1, s.end());
        if (left > right) {
            s += ')';
            generateParenthesis(n, left, right+1, s, ans);
            s.erase(s.end()-1, s.end());
        }
    }
};