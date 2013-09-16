class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3)
        {
            return 0;
        }

        sort(num.begin(), num.end());

        int ret = 0;
        int minDiff = numeric_limits<int>::max();

        for (size_t i = 0; i < num.size()-2; ++i)
        {
            if (i > 0 && num[i] == num[i-1]) continue;

            size_t left = i+1;
            size_t right = num.size()-1;
            while (left < right)
            {
                int t = num[i] + num[left] + num[right];

                if (t == target)
                {
                    return t;
                }

                if (abs(t-target) < minDiff)
                {
                    ret = t;
                    minDiff = abs(t-target);
                }

                if (t < target)
                    ++left;
                else if (t > target)
                    --right;
            }
        }

        return ret;
    }
};