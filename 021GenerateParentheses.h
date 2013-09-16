class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        static vector<vector<string> > parenMap;
        if (n <= parenMap.size())
        {
            return parenMap[n-1];
        }

        if (1 == n)
        {
            parenMap.push_back(vector<string>(1, "()"));
            return parenMap[0];
        }

        vector<string> ret;
        vector<string> r = generateParenthesis(n-1);
        for (vector<string>::const_iterator i = r.begin(); i != r.end(); ++i) // (Fn-1)
        {
            ret.push_back("(" + *i + ")");
        }

        for (int i = 1; i < n; ++i)
        {
            vector<string> r1 = generateParenthesis(i);
            vector<string> r2 = generateParenthesis(n-i);

            for (vector<string>::const_iterator it1 = r1.begin(); it1 != r1.end(); ++it1)
            {
                for (vector<string>::const_iterator it2 = r2.begin(); it2 != r2.end(); ++it2)
                {
                    ret.push_back(*it1 + *it2);
                }
            }
        }

        sort(ret.begin(), ret.end());

        r.clear();

        r.push_back(ret[0]);
        for (vector<string>::const_iterator i = ret.begin() + 1; i != ret.end(); ++i)
        {
            if (*i != *(i-1)) r.push_back(*i);
        }

        parenMap.push_back(r);

        return r;
    }
};