class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = word1.size(), n = word2.size();
        vector<vector<int> > distance(2, vector<int>(n+1, 0));
        for (int i = 0; i <= n; ++i) distance[0][i] = i;
        int target = 1;
        for (int i = 1; i <= m; ++i) {
            distance[target][0] = distance[1-target][0] + 1;
            for (int j = 1; j <= n; ++j) {
                int t = min(distance[target][j-1], distance[1-target][j]) + 1;
                if (word1[i-1] == word2[j-1]) t = min(t, distance[1-target][j-1]);
                else t = min(t, distance[1-target][j-1]+1);
                distance[target][j] = t;
            }
            target = 1 - target;
        }
        return distance[1-target][n];
    }
};