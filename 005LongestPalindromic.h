class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return "";
        int len = 2 * s.length() + 3;
        string str(len, '#');
        str[len-1] = '$';
        for (string::iterator i = s.begin(), j = str.begin()+2; i != s.end(); ++i, j += 2)
            *j = *i;
        int farthest = 0, center = 0;
        vector<int> palindrome_length(len, 0);
        for (int i = 1; i < len-1; ++i) {
            if (i < farthest) {
                int j = 2*center - i;
                if (palindrome_length[j] + i <= farthest) {
                    palindrome_length[i] = palindrome_length[j];
                } else {
                    palindrome_length[i] = max(farthest-i-1, 0);
                }
            }
            while (str[i+palindrome_length[i]+1] == str[i-palindrome_length[i]-1])
                ++palindrome_length[i];
            if (i + palindrome_length[i] > farthest) {
                farthest = i + palindrome_length[i];
                center = i;
            }
        }
        farthest = center = 0;
        for (int i = 2; i < len-1; ++i) {
            if (palindrome_length[i] > farthest) {
                farthest = palindrome_length[i];
                center = i;
            }
        }
        return s.substr((center-farthest-1)/2, farthest);
    }
};