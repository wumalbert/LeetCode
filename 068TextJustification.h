class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        //if the length of a word is larger than L ??
        if (1 == L) return words;

        vector<string> ret;
        int count = 0;
        int last = 0;
        int i = 0;
        for (i = 0; i < words.size(); ++i)
        {
            if ((i == 0 && count+words[i].length() > L) || (i > 0 && count+1+words[i].length() > L))
            {
                string str;
                int totalSpace = L - count;
                int nSep = i - last - 1;

                if (0 == nSep)
                {
                    str += words[last];
                    str += string(totalSpace, ' ');
                    ret.push_back(str);

                    count = words[i].length();
                    last = i;
                    continue;
                }
                int t = last + totalSpace % nSep-1;
                string s1(totalSpace/nSep+2, ' ');
                string s2(totalSpace/nSep+1, ' ');

                int j;
                for (j = last; j <= t; ++j)
                {
                    str += words[j];
                    str += s1;
                }
                for (; j < i-1; ++j)
                {
                    str += words[j];
                    str += s2;
                }
                str += words[j];
                ret.push_back(str);

                count = words[i].length();
                last = i;
            }
            else
            {
                if (i == last) count += words[i].length();
                else count += 1 + words[i].length();
            }
        }

        // the last line
        string str;
        for(int j = last; j < i-1; ++j)
        {
            str += words[j];
            str += " ";
        }
        str += words[i-1];
        str += string(L-str.length(), ' ');
        ret.push_back(str);

        return ret;
    }
};