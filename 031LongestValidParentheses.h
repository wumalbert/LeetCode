class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> leftPos; // store positions of the left parenthesis

        int last = -1; //record the last position of invaild parenthesis
        int maxLength = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if ('(' == s[i])
            {
                leftPos.push(i);
            }
            else
            {
                if (leftPos.empty()) //the string before is invaild
                {
                    last = i;
                }
                else
                {
                    leftPos.pop();

                    if (leftPos.empty()) //the end of this vaild string
                    {
                        maxLength = max(maxLength, i - last);
                    }
                    else //the vaild parenthesis may be longer
                    {
                        maxLength = max(maxLength, i - leftPos.top());
                    }
                }
            }
        }

        return maxLength;
    }
};