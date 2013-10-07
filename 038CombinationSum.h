class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = candidates.size()+1, n = target+1;
        if (candidates.empty()) return vector<vector<int> >();
        sort(candidates.begin(), candidates.end());
        // using dynamic programming method 01 knapsack
        // dpResult[i][j]: the weight limit j by using the first i items
        vector<int> dpResult(n, numeric_limits<int>::min());
        vector<vector<vector<int> > > stateTrace(n, vector<vector<int> >());
        dpResult[0] = 0;
        stateTrace[0] = vector<vector<int> >(1, vector<int>());
        for (int i = 1; i < m; ++i) {
            if (i > 1 && candidates[i-1] == candidates[i-2]) continue;
            int t = candidates[i-1];
            for (int j = t; j < n; ++j) {
                if (dpResult[j-t]+t < j) {
                    continue;
                } else if (dpResult[j-t]+t == j) {
                    for (int k = 0; k < stateTrace[j-t].size(); ++k) {
                        stateTrace[j].push_back(stateTrace[j-t][k]);
                        stateTrace[j].back().push_back(t);
                    }
                    dpResult[j] = j;
                }
            }
        }
        return stateTrace[n-1];
    }
};
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> current;
        dfs(candidates, target, current, ret, 0, 0);
        return ret;
    }
private:
    void dfs(vector<int> &candidates, int target, vector<int> &current, vector<vector<int> > &ans, int index, int current_sum) {
        if (candidates.size() == index) {
            if (current_sum == target) ans.push_back(current);
            return;
        }
        dfs(candidates, target, current, ans, index+1, current_sum);
        if (current_sum + candidates[index] <= target) {
            current.push_back(candidates[index]);
            dfs(candidates, target, current, ans, index, current_sum + candidates[index]);
            current.pop_back();
        }
    }
};