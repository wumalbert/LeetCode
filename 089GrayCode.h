class Solution {
private:
    void grayCodeRecursive(int n, vector<int>& ans)
    {
        if (0 == n)
        {
            ans.push_back(0);
        }
        else
        {
            grayCodeRecursive(n-1, ans);
            
            int t = 1 << (n-1);
            for (int i = ans.size()-1; i >= 0; --i)
            {
                ans.push_back(ans[i] + t);
            }
        }
    }
    
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        
        grayCodeRecursive(n, ret);
        
        return ret;
    }
};