class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (1 > n) return "";
        if (1 == n) return "1";

        string ret = "1";
        for (int i = 1; i < n; ++i)
        {
            int j = 1;
            int count = 1;
            string s;
            while (j < ret.length())
            {
                if (ret[j] == ret[j-1])
                    ++count;
                else
                {
                    char c = count + '0';
                    s += c;
                    s += ret[j-1];

                    count = 1;
                }
                ++j;
            }
            char c = count + '0';
            s += c;
            s += ret[j-1];

            ret = s;
        }

        return ret;
    }
};