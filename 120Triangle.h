class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int row = triangle.size();
        vector<vector<int> > sum(2, vector<int>(row, 0));
        sum[0][0] = triangle[0][0];
        int target = 1;
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j <= i; ++j) {
                sum[target][j] = numeric_limits<int>::max();
                if (j > 0) sum[target][j] = min(sum[target][j], sum[1-target][j-1] + triangle[i][j]);
                if (j < i) sum[target][j] = min(sum[target][j], sum[1-target][j] + triangle[i][j]);
            }
            target = 1 - target;
        }
        target = 1 - target;
        int minSum = sum[target][0];
        for (int i = 1; i < row; ++i) {
            if (sum[target][i] < minSum) minSum = sum[target][i];
        }
        return minSum;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (triangle.empty()) return numeric_limits<int>::max();
        vector<int> minimal_total(triangle.size(), 0);
        minimal_total[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            int j = triangle[i].size()-1;
            minimal_total[j] = minimal_total[j-1] + triangle[i][j];
            for (--j; j > 0; --j) {
                minimal_total[j] = min(minimal_total[j-1], minimal_total[j]) + triangle[i][j];
            }
            minimal_total[0] += triangle[i][0];
        }
        int ret = minimal_total[0];
        for (int i = 1; i < minimal_total.size(); ++i) {
            ret = min(ret, minimal_total[i]);
        }
        return ret;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> sum(triangle.size()+1, 0);
        for (int i = triangle.size()-1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
            }
        }
        return sum[0];
    }
};