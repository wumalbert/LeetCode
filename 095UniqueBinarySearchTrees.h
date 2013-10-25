class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> trees(n+1, 0);
        trees[0] = trees[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                trees[i] += trees[j-1] * trees[i-j];
            }
        }
        return trees[n];
    }
};
class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int number = 1;
        for (int i = 1; i <= n; ++i) {
            number = number * 2 * (2*i - 1) / (i+1);
        }
        return number;
    }
};