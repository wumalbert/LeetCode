class Solution {
private:
    void subsetsRecursive(int k, vector<int>& S, vector<int> sub, vector<vector<int> >& ans)
    {
        if (S.size() == k)
        {
            ans.push_back(sub);
        }
        else
        {
            // not include S[k]  into the subset
            subsetsRecursive(k+1, S, sub, ans);
            
            // include S[k] into the subset
            sub.push_back(S[k]);
            
            subsetsRecursive(k+1, S, sub, ans);
        }
    }
    
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(S.begin(), S.end());
        
        vector<int> sub;
        vector<vector<int> > ret;
        
        subsetsRecursive(0, S, sub, ret);
        
        return ret;
        
    }
};