class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (matrix.empty()) return false;
        int m = matrix.size();
        if (matrix[0].empty()) return false;
        int n = matrix[0].size();
        
        // 1. locate the row
        int left = 0, right = m-1;
        
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) left = mid + 1;
            else if (matrix[mid][0] > target) right = mid - 1;
        }
        
        // (right, left)
        if (right < 0) return false;
        int row = right;
        
        left = 0;
        right = n-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) left = mid + 1;
            else if (matrix[row][mid] > target) right = mid - 1;
        }
        return false;
    }
};