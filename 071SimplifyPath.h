class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        stack<string> pathStack;

        int i = 0;
        int last = -1;
        while (i < path.length())
        {
            if ('/' == path[i])
            {
                string s = path.substr(last+1, i-last);            
                if ("../" == s)
                {
                    if (pathStack.size() > 1) pathStack.pop();
                }
                else if ("./" != s && ("/" != s || -1 == last))
                {
                    pathStack.push(s);
                }

                last = i;
            }
            ++i;
        }
        if (last != path.length()-1)
        {
            string s = path.substr(last+1, path.length()-last);
            if ("." != s && ".." != s)
                pathStack.push(s);
            else if (".." == s && pathStack.size() > 1)
                pathStack.pop();
        }

        if (pathStack.size() <= 1) return "/";

        vector<string> pathArray(pathStack.size(), "");

        i = pathStack.size() - 1;
        while (!pathStack.empty())
        {
            pathArray[i--] = pathStack.top();
            pathStack.pop();
        }

        string ret;
        if ('/' != pathArray[0][0])
            ret += "/";
        for (i = 0; i < pathArray.size()-1; ++i)
        {
            ret += pathArray[i];
        }
        if ('/' == pathArray[i][pathArray[i].size()-1])
            ret += pathArray[i].substr(0, pathArray[i].size()-1);
        else
            ret += pathArray[i];

        return ret;
    }
};