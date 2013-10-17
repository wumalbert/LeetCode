class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        ret.push_back(num);
        while (next(num)) ret.push_back(num);
        return ret;
    }
private:
    bool next(vector<int> &num) {
        int first_decrease = num.size()-2;
        while (first_decrease >= 0 && num[first_decrease] >= num[first_decrease+1])
            --first_decrease;
        if (first_decrease < 0) return false;
        int first_larger = num.size()-1;
        while (first_larger > first_decrease && num[first_larger] <= num[first_decrease])
            --first_larger;
        swap(num.begin() + first_decrease, num.begin() + first_larger);
        reverse(num.begin()+first_decrease+1, num.end());
        return true;
    }
    void swap(vector<int>::iterator a, vector<int>::iterator b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin < 2) return;
        --end;
        while (begin < end) swap(begin++, end--);
    }
};
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        sort(num.begin(), num.end());
        vector<int> permute;
        vector<bool> visited(num.size(), false);
        dfs(num, visited, permute, ret);
        return ret;
    }
private:
    void dfs(vector<int> &num, vector<bool> &visited, vector<int> &permute, vector<vector<int> > &ans) {
        if (permute.size() == num.size()) {
            ans.push_back(permute);
            return;
        }
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && num[i] == num[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            permute.push_back(num[i]);
            dfs(num, visited, permute, ans);
            permute.pop_back();
            visited[i] = false;
        }
    }
};