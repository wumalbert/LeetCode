class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int bought = numeric_limits<int>::max(), ret = 0;
        for (vector<int>::iterator i = prices.begin(); i != prices.end(); ++i) {
            if (*i - bought > ret) ret = *i - bought;
            if (*i < bought) bought = *i;
        }
        return ret;
    }
};