class Solution03 {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) return 0;
        int maxArea = 0;
        stack<int> ids;
        int i = 0;
        while (i <= height.size()) {
            if (ids.empty() || (i != height.size() && height[ids.top()] <= height[i])) {
                ids.push(i++);
            } else {
                int index = ids.top();
                ids.pop();
                maxArea = max(maxArea, height[index] * (ids.empty() ? i : i-ids.top()-1));
            }
        }
        return maxArea;
    }
};
class Solution02 {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<int> index_stack;
        index_stack.push(-1);
        int largest = 0;
        for (int i = 0; i <= height.size(); ) {
            if (index_stack.top() == -1 || (i < height.size() && height[i] >= height[index_stack.top()])) {
                index_stack.push(i++);
            } else {
                int h = height[index_stack.top()];
                index_stack.pop();
                largest = max(largest, h * (i-index_stack.top()-1));
            }
        }
        return largest;
    }
};
class Solution01 {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = height.size();
        if (n < 1) return 0;
        vector<int> left_max_index(n, 0), right_min_index(n, 0);
        for (int i = 0; i < n; ++i)
            calcLeftMaxIndex(height, i, i-1, left_max_index);
        for (int i = n-1; i >= 0; --i)
            calcRightMinIndex(height, i, i+1, right_min_index);
        int largest = 0;
        for (int i = 0; i < n; ++i) {
            largest = max(largest, height[i] * (right_min_index[i]-left_max_index[i]-1));
        }
        return largest;
    }
private:
    void calcLeftMaxIndex(vector<int> &height, int i, int j, vector<int> &left_max_index) {
        if (i == 0 || j == -1) left_max_index[i] = -1;
        else if (height[j] == height[i]) left_max_index[i] = left_max_index[j];
        else if (height[j] < height[i]) left_max_index[i] = j;
        else  calcLeftMaxIndex(height, i, left_max_index[j], left_max_index);
    }
    void calcRightMinIndex(vector<int> &height, int i, int j, vector<int> &right_min_index) {
        if (i == height.size()-1 || j == height.size()) right_min_index[i] = height.size();
        else if (height[j] == height[i]) right_min_index[i] = right_min_index[j];
        else if (height[j] < height[i]) right_min_index[i] = j;
        else calcRightMinIndex(height, i, right_min_index[j], right_min_index);
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<int> index_stack;
        index_stack.push(-1);
        int largest = 0;
        for (int i = 0; i <= height.size(); ++i) {
            int h = i < height.size() ? height[i] : -1;
            while (index_stack.top() >= 0 && height[index_stack.top()] > h) {
                int t = height[index_stack.top()];
                index_stack.pop();
                largest = max(largest, t * (i-index_stack.top()-1));
            }
            index_stack.push(i);
        }
        return largest;
    }
};