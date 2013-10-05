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
// recursive DFS
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<bool> choosed(num.size(), false);
        vector<int> current;
        vector<vector<int> > ret;
        permute(num, choosed, 0, current, ret);
        return ret;
    }
private:
    void permute(const vector<int> &num, vector<bool> &choosed, int index, vector<int> &current, vector<vector<int> > &ans) {
        if (num.size() == index) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (!choosed[i]) {
                choosed[i] = true;
                current.push_back(num[i]);
                permute(num, choosed, index+1, current, ans);
                current.pop_back();
                choosed[i] = false;
            }
        }
    }
};
// more elegant recursive solution
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        dfs(num, 0, ret);
        return ret;
    }
private:
    void dfs(vector<int> &num, int position, vector<vector<int> > &ans) {
        if (num.size() == position) {
            ans.push_back(num);
            return;
        }
        for (int i = position; i < num.size(); ++i) {
            swap(num[i], num[position]);
            dfs(num, position+1, ans);
            swap(num[i], num[position]);
        }
    }
};