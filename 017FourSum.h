class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (num.size() < 4) return ret;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size()-3; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < num.size()-2; ++j) {
                if (j > i+1 && num[j] == num[j-1]) continue;
                int left = j+1, right = num.size()-1;
                while (left < right) {
                    if (left > j+1 && num[left] == num[left-1]) {
                        ++left;
                        continue;
                    }
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if (sum == target) {
                        int v[4] = {num[i], num[j], num[left], num[right]};
                        ret.push_back(vector<int>(v, v+4));
                        ++left;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return ret;
    }
};