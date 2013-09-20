class Solution {
private:
    void swap(int& v1, int& v2)
    {
        if (v1 == v2) return;

        v1 = v1 ^ v2;
        v2 = v1 ^ v2;
        v1 = v1 ^ v2;
    }

public:
    void rotate01(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // (i, j) is mapped to (H-1-j, i)
        int width = matrix.size();

        // 1. tranpose the image
        for (int i = 0; i < width; ++i)
        {
            for (int j = i; j < width; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. swap every row
        for (int i = 0; i < width; ++i)
        {
            int left = 0;
            int right = width-1;
            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
    }

    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // (i, j) is mapped to (H-1-j, i)
        int w = matrix.size();

        for (int i = 0; i < w/2; ++i)
        {
            for (int j = i; j < w-1-i; ++j)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[w-1-j][i];
                matrix[w-1-j][i] = matrix[w-1-i][w-1-j];
                matrix[w-1-i][w-1-j] = matrix[j][w-1-i];
                matrix[j][w-1-i] = t;
            }
        }
    }
};