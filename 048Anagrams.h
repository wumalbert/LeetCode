class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, vector<string> > groups;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
        {
            string key = *it;
            sort(key.begin(), key.end());
            groups[key].push_back(*it);
        }
        
        vector<string> ret;
        for(map<string, vector<string> >::iterator it = groups.begin(); it != groups.end(); ++it)
        {
            if (it->second.size() > 1)
            {
                for (vector<string>::iterator i = it->second.begin(); i != it->second.end(); ++i)
                    ret.push_back(*i);
            }
        }
        
        return ret;
    }
};