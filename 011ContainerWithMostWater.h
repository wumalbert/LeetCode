class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (height.size() < 2) return 0;
        int max_area = 0, left = 0, right = height.size()-1;
        while (left < right) {
            if (height[left] < height[right]) {
                max_area = max(max_area, height[left] * (right - left));
                ++left;
            } else {
                max_area = max(max_area, height[right] * (right - left));
                --right;
            }
        }
        return max_area;
    }
};