class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        // buy at minmum point and sell at maximum point
        int len = prices.size(), low = prices[0], profit = 0;
        bool bought = true; // 
        for (int i = 1; i < len-1; ++i)
        {
            // maxmum point
            if (prices[i] > prices[i-1] && prices[i] >= prices[i+1])
            {
                if (bought)
                {
                    profit += prices[i] - low;
                    bought = false;
                }
            }
            else if (prices[i] <= prices[i-1] && prices[i] < prices[i+1])
            {
                low = prices[i];
                bought = true;
            }
        }
        if (bought && prices[len-1] > low)
            profit += prices[len-1] - low;
        
        return profit;
    }
};