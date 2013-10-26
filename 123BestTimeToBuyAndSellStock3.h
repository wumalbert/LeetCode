class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (prices.size() < 2) return 0;
        int n = prices.size(), bought = prices[0], max_profit = 0;
        vector<int> first_profit(n, 0), second_profit(n, 0);
        for (int i = 1; i < n; ++i) { // [0, i]
            if (prices[i] - bought > max_profit) max_profit = prices[i] - bought;
            first_profit[i] = max_profit;
            if (prices[i] < bought) bought = prices[i];
        }
        int sell = prices[n-1], ret = 0;
        max_profit = 0;
        for (int i = n-1; i >= 0; --i) { // [i, n)
            if (sell - prices[i]> max_profit) max_profit = sell - prices[i];
            second_profit[i] = max_profit;
            if (first_profit[i] + second_profit[i] > ret)
                ret = first_profit[i] + second_profit[i];
            if (prices[i] > sell) sell = prices[i];
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (prices.size() < 2) return 0;
        int n = prices.size();
        vector<int> f(n+1, 0), g(n+1, 0);
        for (int i = 0; i + 1 < n; ++i) {
            int diff = prices[i+1] - prices[i];
            int m = min(i+1, 2);
            for (int j = m; j > 0; --j) {
                f[j] = max(f[j], g[j-1]) + diff;
                g[j] = max(f[j], g[j]);
            }
        }
        return max(g[1], g[2]);
    }
};