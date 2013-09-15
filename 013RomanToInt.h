class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        for (size_t i = 0; i < s.length(); )
        {
            switch (s[i])
            {
                case 'M':
                    result += 1000;
                    ++i;
                    break;
                case 'D':
                    result += 500;
                    ++i;
                    break;
                case 'C':
                    switch (s[i+1])
                    {
                        case 'M':
                            result += 900;
                            i += 2;
                            break;
                        case 'D':
                            result += 400;
                            i += 2;
                            break;
                        default:
                            result += 100;
                            ++i;
                            break;
                    }
                    break;
                case 'L':
                    result += 50;
                    ++i;
                    break;
                case 'X':
                    switch (s[i+1])
                    {
                        case 'C':
                            result += 90;
                            i += 2;
                            break;
                        case 'L':
                            result += 40;
                            i += 2;
                            break;
                        default:
                            result += 10;
                            ++i;
                            break;
                    }
                    break;
                case 'V':
                    result += 5;
                    ++i;
                    break;
                case 'I':
                    switch (s[i+1])
                    {
                        case 'X':
                            result += 9;
                            i += 2;
                            break;
                        case 'V':
                            result += 4;
                            i += 2;
                            break;
                        default:
                            result += 1;
                            ++i;
                            break;
                    }
                    break;
            }
        }
        
        return result;
    }
};