class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int bought = 0, sell = -1, ret = 0;
        while (sell + 2 < prices.size()) {
            for (bought = sell+1; bought+1 < prices.size() && prices[bought] >= prices[bought+1]; ++bought) {}
            for (sell = bought+1; sell+1 < prices.size() && prices[sell] <= prices[sell+1]; ++sell) {}
            if (sell < prices.size()) ret += prices[sell] - prices[bought];
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int bought = 0, sell = -1, ret = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (i > 0 && prices[i] > prices[i-1])
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        for (int i = 0, j = 0; i + 1 < prices.size(); ++i) {
            for (j = i+1; j < prices.size() && prices[j-1] <= prices[j]; ++j) {}
            ret += prices[j-1] - prices[i];
            i = j-1;
        }
        return ret;
    }
};