class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        int low = prices[0], high = prices[0], profit = numeric_limits<int>::min();
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < low)
            {
                if (high - low > profit) profit = high - low;
                
                low = prices[i];
                high = low;
            }
            else if (prices[i] > high)
            {
                high = prices[i];
            }
        }
        
        if (high - low > profit) profit = high - low;
        return profit;
    }
};