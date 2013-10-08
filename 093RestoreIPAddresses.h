class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ip;
        vector<string> ret;
        dfs(s, 0, 0, ip, ret);
        return ret;
    }
private:
    void dfs(string &s, int str_index, int ip_index, string &ip, vector<string> &ans) {
        if (4 == ip_index && str_index == s.size()) {
            ans.push_back(ip.substr(0, ip.size()-1));
            return;
        }
        if (ip_index >= 4 || str_index >= s.size()) return;
        if ('0' == s[str_index]) {
            ip.append("0.");
            dfs(s, str_index+1, ip_index+1, ip, ans);
            ip.resize(ip.size()-2);
        } else {
            int num = 0;
            for (int i = 0; i < 3 && str_index+i < s.size(); ++i) {
                num = num * 10 + s[str_index+i] - '0';
                if (num < 256) {
                    ip = ip + s.substr(str_index, i+1) + ".";
                    dfs(s, str_index+i+1, ip_index+1, ip, ans);
                    ip.resize(ip.size()-i-2);
                }
            }
        }
    }
};