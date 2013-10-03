class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if(num.size() < 3) return ret;
        
        sort(num.begin(), num.end());
        for(vector<int>::const_iterator i = num.begin(); i != num.end(); ++i)
        {
            if(i > num.begin() && *i == *(i-1)) continue;
            vector<int>::const_iterator left = i+1, right = num.end()-1;
            while(left < right)
            {
                if(*i + *left + *right == 0)
                {
                    vector<int> v({*i, *left, *right});
                    ret.push_back(v);
                    
                    for(++left; *left == *(left-1); ++left);
                    for(--right; *right == *(right+1); --right);
                }
                else if(*i + *left + *right < 0) ++left;
                else --right;
            }
        }
        return ret;
    }
};