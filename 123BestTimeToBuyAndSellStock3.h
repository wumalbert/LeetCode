class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        int len = prices.size();
        // firstProfit[i]: maximum profit of prices[0, i)
        vector<int> firstProfit(len+1, 0);
        int low = prices[0], high = prices[0];
        for (int i = 1; i < len; ++i)
        {
            if (prices[i] < low)
            {
                high = low = prices[i];
            }
            else if (prices[i] > high)
            {
                high = prices[i];
            }
            firstProfit[i+1] = max(firstProfit[i], high - low);
        }
        
        // secondProfit[i]: maximum profit of prices [i, end)
        vector<int> secondProfit(len+1, 0);
        low = high = prices[len-1];
        for (int i = len-2; i >= 0; --i)
        {
            if (prices[i] < low)
            {
                low = prices[i];
            }
            else if (prices[i] > high)
            {
                low = high = prices[i];
            }
            secondProfit[i] = max(secondProfit[i+1], high - low);
        }
        
        // use dynamic programming to find the maximum profit
        int profit = numeric_limits<int>::min();
        for (int i = 0; i <= len; ++i)
        {
            if (firstProfit[i] + secondProfit[i] > profit)
                profit = firstProfit[i] + secondProfit[i];
        }
        
        return profit;
    }
};