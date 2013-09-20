class Solution {
private:
    static const int kSize = 4;
    static const int kSep = 10000;

    void convertToIntegers(const string& str, vector<int>& v)
    {
        int n = (str.length() + kSize - 1) / kSize;
        int start = str.length() - kSize;
        for (int i = 0; i < n-1; ++i)
        {
            v[i] = atoi(str.substr(start, kSize).c_str());
            start -= kSize;
        }
        v[n-1] = atoi(str.substr(0, str.length()-(n-1)*kSize).c_str());
    }

    int stringToInt(const string& str)
    {
        int ret = 0;

        for (int i = 0; i < str.length(); ++i)
        {
            ret *= 10;
            ret += str[i] - '0';
        }

        return ret;
    }

    string intToString(int v, bool fill)
    {
        string ret;

        while (v/10 != 0)
        {
            ret += v%10 + '0';
            v = v/10;
        }
        ret += v%10 + '0';

        if (fill)
        {
            for (int i = ret.size(); i < kSize; ++i)
                ret += '0';
        }

        for (int i = 0, j = ret.length()-1; i < j; ++i, --j)
        {
            ret[i] = ret[i] ^ ret[j];
            ret[j] = ret[i] ^ ret[j];
            ret[i] = ret[i] ^ ret[j];
        }

        return ret;
    }

public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1.empty() || num2.empty()) return "";

        int n1 = (num1.length()+kSize-1)/kSize;
        int n2 = (num2.length()+kSize-1)/kSize;
        vector<int> v1(n1, 0);
        vector<int> v2(n2, 0);

        convertToIntegers(num1, v1);
        convertToIntegers(num2, v2);

        int len = n1 + n2;
        vector<int> result(len, 0);
        int carry = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j <= i && j < n1; ++j)
            {
                if (i - j < n2) result[i] += v1[j]*v2[i-j];
            }
            result[i] += carry;
            carry = result[i] / kSep;
            result[i] = result[i] % kSep;
        }

        string ret;

        int i = len - 1;
        for (; i >= 0 && 0 == result[i]; --i);
        if (i < 0) return "0";

        ret += intToString(result[i], false);

        for (i = i-1; i >= 0; --i)
            ret += intToString(result[i], true);

        return ret;
    }
};