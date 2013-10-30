class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (ratings.empty()) return 0;
        int n = ratings.size(), count = 1;
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) ++count;
            else count = 1;
            candies[i] = max(candies[i], count);
        }
        count = 1;
        int total_candies = candies[n-1];
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) ++count;
            else count = 1;
            candies[i] = max(candies[i], count);
            total_candies += candies[i];
        }
        return total_candies;
    }
};
class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (ratings.empty()) return 0;
        int n = ratings.size(), count = 1, total_candies = 1;
        int max_index = 0, max_candy = 0;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i-1]) {
                count = ratings[i] == ratings[i-1] ? 1 : count+1;
                max_candy = count;
                max_index = i;
            } else {
                if (1 == count) {
                    if (max_candy <= i - max_index) {
                        total_candies += i - max_index;
                        ++max_candy;
                    } else {
                        total_candies += i - max_index - 1;
                    }
                }
                count = 1;
            }
            total_candies += count;
        }
        return total_candies;
    }
};