class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ret;
        string str;
        letterCombinations(ret, str, digits, 0);
        return ret;
    }
private:
    void letterCombinations(vector<string>& results, string& str, const string& digits, int index) {
        static const string digit_alpha_map[] = {" ", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (index == digits.size()) {
            results.push_back(str);
            return;
        }
        int number = digits[index] - '0';
        for (int j = 0; j < digit_alpha_map[number].length(); ++j) {
            str.append(1, digit_alpha_map[number][j]);
            letterCombinations(results, str, digits, index+1);
            str.resize(str.size()-1);
        }
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ret(1, "");
        static const string digit_alpha_map[] = {" ", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.length(); ++i) {
            if ('0' != digits[i]) {
                for (int j = ret.size()-1; j >= 0; --j) {
                    for (int k = digit_alpha_map[digits[i]-'0'].length() - 1; k > 0; --k) {
                        ret.push_back(ret[j]);
                        ret.back().append(1, digit_alpha_map[digits[i]-'0'][k]);
                    }
                    ret[j].append(1, digit_alpha_map[digits[i]-'0'][0]);
                }
            }
        }
        return ret;
    }
};