class Solution {

public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string result;
        
        static const int basicInt[13] = {1, 4, 5, 9, 10, 40, 50, 
            90, 100, 400, 500, 900, 1000};
        static const string basicRoman[13] = {"I", "IV", "V", "IX", 
            "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        for (int i = 12; i >= 0; --i)
        {
            int t = num / basicInt[i];
            for (int j = 0; j < t; ++j)
                result += basicRoman[i];
            num = num % basicInt[i];
            
        }
        
        return result;
    }
};