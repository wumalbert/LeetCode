class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size()-1;
        while (left <= right) {
            int middle = left + (right - left >> 1);
            if (matrix[middle][0] == target) return true;
            else if (matrix[middle][0] < target) left = middle + 1;
            else right = middle - 1;
        }
        if (right < 0) return false;
        int row = right;
        left = 0;
        right = matrix[row].size()-1;
        while (left <= right) {
            int middle = left + (right-left >> 1);
            if (matrix[row][middle] == target) return true;
            else if (matrix[row][middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        return false;
    }
};