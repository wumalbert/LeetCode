class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        static const string roman_base[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        static const int int_base[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ret;
        for (int i = sizeof(int_base) / sizeof(int_base[0]) - 1; i >= 0 && num; --i) {
            int len = num / int_base[i];
            for (int j = 0; j < len; ++j) ret += roman_base[i];
            num = num % int_base[i];
        }
        return ret;
    }
};