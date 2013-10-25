class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> paths;
        for (int i = 0, last = -1; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (i == 0 || i-last > 1) paths.push_back(path.substr(last+1, i-last));
                last = i;
            } else if (path[i] == '.') {
                if (i + 1 == path.size()) {
                    break;
                } else if (path[i+1] == '.') {
                    if ((i + 2 == path.size() || (i + 2 < path.size() && path[i+2] == '/')) && paths.size() > 1) paths.pop_back();
                    last = i = i+2;
                } else if (path[i+1] == '/') {
                    last = i = i+1;
                }
            }
        }
        string ret;
        for (vector<string>::iterator it = paths.begin(); it != paths.end(); ++it)
            ret += *it;
        if (ret.size() > 1 && ret[ret.size()-1] == '/') ret = ret.substr(0, ret.size()-1);
        return ret;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> paths;
        for (int start = 1, end = 1; end < path.length(); ++end) {
            for (start = end; start < path.length() && path[start] == '/'; ++start) {}
            for (end = start+1; end < path.length() && path[end] != '/'; ++end) {}
            string s = path.substr(start, end-start);
            if (s.empty() || s == ".") {
                continue;
            } else if (s == "..") {
                if (!paths.empty()) paths.pop_back();
            } else {
                paths.push_back(s); 
            }
        }
        if (paths.empty()) return "/";
        string ret;
        for (vector<string>::iterator it = paths.begin(); it != paths.end(); ++it)
            ret += "/" + *it;
        return ret;
    }
};