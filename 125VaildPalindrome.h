class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s.empty()) return true;
        string::const_iterator left = s.begin(), right = s.end()-1;
        while(left < right)
        {
            if(!isalpha(*left) && !isdigit(*left)) ++left;
            else if(!isalpha(*right) && !isdigit(*right)) --right;
            else 
            {
                char ch1 = isalpha(*left) ? tolower(*left) : *left;
                char ch2 = isalpha(*right) ? tolower(*right) : *right;
                if(ch1 == ch2)
                {
                    ++left;
                    --right;
                }
                else return false;
            }
        }
        return true;
    }
};