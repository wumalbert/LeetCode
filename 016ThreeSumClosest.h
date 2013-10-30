class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int closest = target > 0 ? numeric_limits<int>::max() : numeric_limits<int>::max() + target;
        for (int i = 0; i < num.size()-2; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue;
            int left = i+1, right = num.size()-1;
            while (left < right) {
                int sum = num[i] + num[left] + num[right];
                if (abs(sum - target) < abs(closest - target)) closest = sum;
                if (sum == target) return closest;
                else if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};