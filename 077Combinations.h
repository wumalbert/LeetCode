class Solution01 {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret, allCombines(1, vector<int>());
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = allCombines.size()-1; j >= 0; --j)
            {
                if (allCombines[j].size() == k-1)
                {
                    ret.push_back(allCombines[j]);
                    ret.back().push_back(i);
                    continue;
                }
                // the current combination corresponse to the one not choose i 
                allCombines.push_back(allCombines[j]); // copy the current combination
                allCombines.back().push_back(i); // choose i
            }
        }
        
        return ret;
    }
};

class Solution {
private:
    // choose k numbers from [start, end)
    void combineRecursive(int start, int end, int k, vector<int> &path, vector<vector<int> > &ans)
    {
        if (k > end - start) return;
        if (0 == k) ans.push_back(path);
        else
        {
            combineRecursive(start+1, end, k, path, ans);
            path.push_back(start);
            combineRecursive(start+1, end, k-1, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> path;
        vector<vector<int> > ret;
        combineRecursive(1, n+1, k, path, ret);
        return ret;
    }
};