class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = height.size()-1;

        int maxarea = 0;
        while (left < right)
        {
            maxarea = max(maxarea, min(height[left], height[right]) * (right - left));

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return maxarea;
    }
};