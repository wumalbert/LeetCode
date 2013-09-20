class Solution {    
private:
    void swap(int& v1, int& v2)
    {
        if (v1 == v2) return;

        v1 = v1 ^ v2;
        v2 = v1 ^ v2;
        v1 = v1 ^ v2;
    }

    bool nextPermute(vector<int>& num)
    {
        // find the first descending element
        int i = 0;
        for (i = num.size()-2; i >= 0 && num[i] >= num[i+1]; --i);

        if (i < 0) return false;

        // find the first element larger than num[i]
        int j = 0;
        for (j = num.size() - 1; j > i && num[j] <= num[i]; --j);

        swap(num[i], num[j]);

        ++i;
        j = num.size() - 1;
        while (i < j)
        {
            swap(num[i], num[j]);
            ++i;
            --j;
        }
        return true;
    }

public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > ret;

        if (num.empty()) return ret;

        sort(num.begin(), num.end());

        ret.push_back(num);

        while (nextPermute(num))
        {
            ret.push_back(num);
        }

        return ret;
    }
};