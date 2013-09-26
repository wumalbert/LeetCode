class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) return 0;
        
        int maxArea = 0;
        
        stack<int> ids;
        ids.push(0);
        int i = 0;
        while (i <= height.size())
        {
            if (ids.empty() || (i != height.size() && height[ids.top()] <= height[i]))
            {
                ids.push(i++);
            }
            else
            {
                int index = ids.top();
                ids.pop();
                maxArea = max(maxArea, height[index] * (ids.empty() ? i : i-ids.top()-1));
            }
        }
        return maxArea;
    }
};