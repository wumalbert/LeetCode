class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> symbolStack;

        for (size_t i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                symbolStack.push(s[i]);
                break;
            case ')':
                if (symbolStack.empty() || symbolStack.top() != '(')
                    return false;
                symbolStack.pop();
                break;
            case ']':
                if (symbolStack.empty() || symbolStack.top() != '[')
                    return false;
                symbolStack.pop();
                break;
            case '}':
                if (symbolStack.empty() || symbolStack.top() != '{')
                    return false;
                symbolStack.pop();
                break;
            }
        }
        return symbolStack.empty();
    }
};