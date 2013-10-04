#include <unordered_map>
using namespace std;

class Solution01 {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // static const string roman_base[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        // static const int int_base[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case 'M' :
                    ret += 1000;
                    break;
                case 'D' :
                    ret += 500;
                    break;
                case 'C' :
                    ++i;
                    if (i < s.length() && 'M' == s[i]) {
                        ret += 900;
                    } else if (i < s.length() && 'D' == s[i]) {
                        ret += 400;
                    } else {
                        ret += 100;
                        --i;
                    }
                    break;
                case 'L' :
                    ret += 50;
                    break;
                case 'X' :
                    ++i;
                    if (i < s.length() && 'C' == s[i]) {
                        ret += 90;
                    } else if (i < s.length() && 'L' == s[i]) {
                        ret += 40;
                    } else {
                        ret += 10;
                        --i;
                    }
                    break;
                case 'V' :
                    ret += 5;
                    break;
                case 'I' :
                    ++i;
                    if (i < s.length() && 'X' == s[i]) {
                        ret += 9;
                    } else if (i < s.length() && 'V' == s[i]) {
                        ret += 4;
                    } else {
                        ret += 1;
                        --i;
                    }
                    break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return 0;
        unordered_map<char, int> roman_decimal_map;
        roman_decimal_map['M'] = 1000;
        roman_decimal_map['D'] = 500;
        roman_decimal_map['C'] = 100;
        roman_decimal_map['L'] = 50;
        roman_decimal_map['X'] = 10;
        roman_decimal_map['V'] = 5;
        roman_decimal_map['I'] = 1;
        int ret = roman_decimal_map[s[s.length()-1]];
        for (string::iterator i = s.begin(); i+1 != s.end(); ++i) {
            if (roman_decimal_map[*i] < roman_decimal_map[*(i+1)])
                ret -= roman_decimal_map[*i];
            else
                ret += roman_decimal_map[*i];
        }
        return ret;
    }
};