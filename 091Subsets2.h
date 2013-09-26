class Solution {
private:
    void subsetsWithDupRecursive(vector<int> &S, int index, 
        vector<int> sub, vector<vector<int> >& ans)
    {
        if (S.size() == index)
        {
            ans.push_back(sub);
        }
        else
        {
            int i;
            for (i = index+1; i < S.size() && S[i] == S[index]; ++i);
            
            for (int j = index; j <= i; ++j)
            {
                subsetsWithDupRecursive(S, i, sub, ans);
                sub.push_back(S[index]);
            }
        }
        
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        
        vector<int> sub;
        vector<vector<int> > ret;
        subsetsWithDupRecursive(S, 0, sub, ret);
        
        return ret;
    }
};