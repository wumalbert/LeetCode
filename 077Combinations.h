class Solution {
private:
    void combineRecursive(int n, int k, int index, vector<int> combine, vector<vector<int> >& allCombines)
    {
        if (0 == k)
        {
            allCombines.push_back(combine);
        }
        else if (k > 0 && index <= n)
        {
            combine.push_back(index);
            combineRecursive(n, k-1, index+1, combine, allCombines);
        
            combine.pop_back();
            combineRecursive(n, k, index+1, combine, allCombines);
        }
        
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> combine;
        
        combineRecursive(n, k, 1, combine, ret);
        
        return ret;
    }
};