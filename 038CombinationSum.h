class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = candidates.size()+1;
        int n = target+1;

        if (candidates.empty()) return vector<vector<int> >();

        sort(candidates.begin(), candidates.end());

        // using dynamic programming method 01 knapsack
        // dpResult[i][j]: the weight limit j by using the first i items
        vector<int> dpResult(n, numeric_limits<int>::min());
        vector<vector<vector<int> > > stateTrace(n, vector<vector<int> >());

        dpResult[0] = 0;
        stateTrace[0] = vector<vector<int> >(1, vector<int>());

        for (int i = 1; i < m; ++i)
        {
            if (i > 1 && candidates[i-1] == candidates[i-2]) continue;

            int t = candidates[i-1];
            for (int j = t; j < n; ++j)
            {
                if (dpResult[j-t]+t < j) continue;
                else if (dpResult[j-t]+t == j)
                {
                    for (int k = 0; k < stateTrace[j-t].size(); ++k)
                    {
                        vector<int> v = stateTrace[j-t][k];
                        v.push_back(t);
                        stateTrace[j].push_back(v);
                    }
                    dpResult[j] = j;
                }
            }
        }

        return stateTrace[n-1];
    }
};