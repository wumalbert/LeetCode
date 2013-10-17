class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // 1. transpose the matrix
        int width = matrix.size();
        for (int i = 0; i < width; ++i) {
            for (int j = i; j < width; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < width; ++i) {
            for (int left = 0, right = width-1; left < right; ++left, --right) {
                swap(matrix[i][left], matrix[i][right]);
            }
        }
    }
private:
    void swap(int &a, int &b) {
        if (a != b) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
    }
};
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int width = matrix.size();
        for (int i = 0; i < width/2; ++i) {
            for (int j = i; j < width-i-1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[width-1-j][i];
                matrix[width-1-j][i] = matrix[width-1-i][width-1-j];
                matrix[width-1-i][width-1-j] = matrix[j][width-1-i];
                matrix[j][width-1-i] = temp;
            }
        }
    }
};