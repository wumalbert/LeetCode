class Solution {
private:
    void restoreIpAddresses(string& s, int i, int j, string ip, vector<string>& ans)
    {
        if (4 == j && s.length() == i)
        {
            ans.push_back(ip.substr(0, ip.size()-1));
        }
        else if (4 > j && s.length() > i)
        {            
            if ('0' == s[i])
            {
                string t = ip + s.substr(i, 1) + ".";
                restoreIpAddresses(s, i+1, j+1, t, ans);
            }
            else
            {
                int k;
                for (k = 1; k < 3; ++k)
                {
                    string t = ip + s.substr(i, k) + ".";
                    restoreIpAddresses(s, i+k, j+1, t, ans);
                }
                
                int v = atoi(s.substr(i, k).c_str());
                if (v < 256)
                {
                    string t = ip + s.substr(i, k) + ".";
                    restoreIpAddresses(s, i+k, j+1, t, ans);
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ip;
        vector<string> ret;
        
        restoreIpAddresses(s, 0, 0, ip, ret);
        
        return ret;
    }
};