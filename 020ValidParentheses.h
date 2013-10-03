class Solution01 {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0;
        for (string::iterator itr = s.begin(); itr != s.end(); ++itr) {
            int t = 0;
            switch (*itr) {
                case '(' : t = 1; break;
                case ')' : t = -1; break;
                case '[' : t = 2; break;
                case ']' : t = -2; break;
                case '{' : t = 3; break;
                case '}' : t = -3; break;
                default: return false;
            }
            if (t > 0) {
                result = result * 4 + t;
            } else {
                if (result % 4 + t != 0) return false;
                else result = result / 4;
            }
        }
        if (0 == result) return true;
        else return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<char> parentheses_stack;
        for (string::iterator itr = s.begin(); itr != s.end(); ++itr) {
            switch (*itr) {
                case '(' :
                case '[' :
                case '{' :
                    parentheses_stack.push(*itr);
                    break;
                case ')' :
                    if (parentheses_stack.empty() || '(' != parentheses_stack.top()) return false;
                    else parentheses_stack.pop();
                    break;
                case ']' :
                    if (parentheses_stack.empty() || '[' != parentheses_stack.top()) return false;
                    else parentheses_stack.pop();
                    break;
                case '}' :
                    if (parentheses_stack.empty() || '{' != parentheses_stack.top()) return false;
                    else parentheses_stack.pop();
                    break;
                default:
                    return false;
            }
        }
        if (parentheses_stack.empty()) return true;
        else return false;
    }
};