class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > row(2, vector<int>(rowIndex+1, 1));
        int target = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                row[target][j] = row[1-target][j-1] + row[1-target][j];
            }
            target = 1 - target;
        }
        return row[1-target];
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret(rowIndex+1, 0);
        ret[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j)
                ret[j] += ret[j-1];
        }
        return ret;
    }
};