class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int left = 0;
        int right = x;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            double t = (double)mid * mid;
            if (t == x) return mid;
            if (t < x) left = mid+1;
            else if (t > x) right = mid-1;
        }

        return right;
    }
};