class Solution {
private:
    void swap(vector<int>& num, int i, int j)
    {
        if (i == j) return;

        num[i] = num[i]^num[j];
        num[j] = num[i]^num[j];
        num[i] = num[i]^num[j];
    }

public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (num.empty() || num.size() <= 1) return;

        // find the first descending index, and the first larger index
        int i = 0, j = 0;
        for (i = num.size()-1; i > 0 && num[i] <= num[i-1]; --i);
        if (i)
        {
            for (j = i; j < num.size() && num[j] > num[i-1]; ++j);   
            swap(num, i-1, j-1);
        }

        // reverse the num from i to end
        j = num.size()-1;
        while (i < j)
        {
            swap(num, i++, j--);
        }
    }
};