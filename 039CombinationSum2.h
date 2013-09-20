#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = candidates.size()+1;
        int n = target+1;

        sort(candidates.begin(), candidates.end());

        if (candidates.empty()) return vector<vector<int> >();

        // using dynamic programming method 01 knapsack
        // dpResult[i][j]: the weight limit j by using the first i items
        vector<int> dpResult(n, numeric_limits<int>::min());
        vector<vector<vector<int> > > stateTrace(n, vector<vector<int> >());

        dpResult[0] = 0;
        stateTrace[0] = vector<vector<int> >(1, vector<int>());

        for (int i = 1; i < m; ++i)
        {
            int t = candidates[i-1];
            int left = t;
            for (int j = i-2; j >= 0 && candidates[j] == candidates[j+1]; --j)
                left += candidates[j];

            for (int j = n-1; j >= left; --j)
            {
                if (dpResult[j-t]+t < j) continue;
                else if (dpResult[j-t]+t == j)
                {
                    for (int k = stateTrace[j-t].size()-1; k >= 0; --k)
                    {
                        int count = 0;
                        vector<int> v = stateTrace[j-t][k];
                        for (int p = v.size()-1; p >= 0 && v[p] == t; ++count,--p);
                        if (count == left/t - 1)
                        {
                            v.push_back(t);
                            stateTrace[j].push_back(v);
                        }
                        else break;
                    }
                    dpResult[j] = j;
                }
            }
        }

        return stateTrace[n-1];
    }
};