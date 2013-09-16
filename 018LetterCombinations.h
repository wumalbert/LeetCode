class Solution {
private:
    void letterCombinations(vector<string>& results, string& str, size_t& nZero, 
        const string& digits, size_t i)
    {
        static const string digitMap[] = {" ", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if (i == digits.size())
        {
            results.push_back(str);
            return;
        }


        if (digits[i] == '0')
        {
            ++nZero;

            letterCombinations(results, str, nZero, digits, i+1);

            str = str.substr(0, i-nZero);
        }
        else
        {
            for (size_t j = 0; j < digitMap[digits[i] - '0'].length(); ++j)
            {
                str += digitMap[digits[i] - '0'][j];

                letterCombinations(results, str, nZero, digits, i+1);

                str = str.substr(0, i-nZero);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<string> ret;
        string str;
        size_t nZero = 0;

        letterCombinations(ret, str, nZero, digits, 0);

        return ret;
    }
};