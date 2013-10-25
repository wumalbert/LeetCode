class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (numRows <= 0) return ret;
        ret.resize(numRows, vector<int>());
        ret[0].push_back(1);
        for (int i = 1; i < numRows; ++i) {
            ret[i].resize(i+1, 1);
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
        return ret;
    }
};