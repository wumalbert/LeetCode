class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > result;

        sort(num.begin(), num.end());

        for (size_t i = 0; i < num.size()-2; ++i)
        {
            if (i > 0 && num[i] == num[i-1]) continue;

            size_t j = i+1;
            size_t k = num.size()-1;

            while (j < k)
            {
                if (num[i] + num[j] + num[k] == 0)
                {   
                    vector<int> t(3, 0);
                    t[0] = num[i];
                    t[1] = num[j];
                    t[2] = num[k];

                    result.push_back(t);

                    for (j = j+1; num[j] == num[j-1] && j < k; ++j);
                    for (k = k-1; num[k] == num[k+1] && k > j; --k);
                }
                else if (num[i] + num[j] + num[k] < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }

        return result;
    }
};