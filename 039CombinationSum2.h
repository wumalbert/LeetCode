class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = num.size()+1, n = target+1;
        sort(num.begin(), num.end());
        if (num.empty()) return vector<vector<int> >();
        // using dynamic programming method 01 knapsack
        // dpResult[i][j]: the weight limit j by using the first i items
        vector<int> dpResult(n, numeric_limits<int>::min());
        vector<vector<vector<int> > > stateTrace(n, vector<vector<int> >());
        dpResult[0] = 0;
        stateTrace[0] = vector<vector<int> >(1, vector<int>());
        for (int i = 1; i < m; ++i) {
            int t = num[i-1], left = t;
            for (int j = i-2; j >= 0 && num[j] == num[j+1]; --j) left += num[j];
            for (int j = n-1; j >= left; --j) {
                if (dpResult[j-t]+t < j) {
                    continue;
                } else if (dpResult[j-t]+t == j) {
                    for (int k = stateTrace[j-t].size()-1; k >= 0; --k) {
                        int count = 0;
                        vector<int> v = stateTrace[j-t][k];
                        for (int p = v.size()-1; p >= 0 && v[p] == t; ++count,--p) {}
                        if (count == left/t - 1) {
                            v.push_back(t);
                            stateTrace[j].push_back(v);
                        }
                        else {
                            break;
                        }
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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> current;
        dfs(num, target, current, ret, 0, 0);
        return ret;
    }
private:
    void dfs(vector<int> &num, int target, vector<int> &current, vector<vector<int> > &ans, int index, int sum) {
        if (num.size() == index) {
            if (sum == target) ans.push_back(current);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (i > index && num[i] == num[i-1]) continue;
            if (sum + num[i] <= target) {
                current.push_back(num[i]);
                dfs(num, target, current, ans, i+1, sum + num[i]);
                current.pop_back();
            }
        }
        dfs(num, target, current, ans, num.size(), sum);
    }
};