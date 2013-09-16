class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;

        if (num.size() < 4) return ret;

        sort(num.begin(), num.end());

        size_t i = 0;
        while (i < num.size()-3)
        {   
            size_t j = i + 1;
            while (j < num.size() - 2)
            {   
                size_t left = j+1;
                size_t right = num.size() - 1;

                while (left < right)
                {
                    int t = num[i] + num[j] + num[left] + num[right];
                    if (t == target)
                    {
                        int v[4] = {num[i], num[j], num[left], num[right]};
                        ret.push_back(vector<int>(v, v+4));

                        for (++left; num[left] == num[left-1] && left < right; ++left);
                        for (--right; num[right] == num[right+1] && left < right; --right);
                    }
                    else if (t < target)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
                for (++j; num[j] == num[j-1]; ++j);
            }
            for (++i; num[i] == num[i-1]; ++i);
        }

        return ret;
    }
};