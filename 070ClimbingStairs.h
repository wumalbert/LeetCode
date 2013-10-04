class Solution01 {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int first = 1, second = 1;
        for (int i = 1; i < n; ++i) {
            int t = first + second;
            second = first;
            first = t;
        }
        return first;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // [F(n), F(n-1); F(n-1), F(n-2)] = [1, 1; 1, 0]^(n-2) [F2, F1; F1, F0]
        if (0 == n || 1 == n) return 1;
        else if (2 == n) return 2;
        Matrix steps(1, 1, 1, 0);
        steps = Pow(steps, n-2);
        steps = Multiply(steps, Matrix(2, 1, 1, 1));
        return steps.m[0][0];
    }
private:
    struct Matrix {
        int m[2][2];

        Matrix(int m00, int m01, int m10, int m11) {
            m[0][0] = m00;
            m[0][1] = m01;
            m[1][0] = m10;
            m[1][1] = m11;
        }
    };
    Matrix Multiply(const Matrix &a, const Matrix &b) {
        Matrix ret(0, 0, 0, 0);
        ret.m[0][0] = a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0];
        ret.m[0][1] = a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1];
        ret.m[1][0] = a.m[1][0]*b.m[0][0] + a.m[1][1]*b.m[1][0];
        ret.m[1][1] = a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1];
        return ret;
    }
    Matrix Pow(Matrix a, int n) {
        Matrix ret(1, 0, 0, 1);
        while (n) {
            if (n & 0x1) ret = Multiply(ret, a);
            a = Multiply(a, a);
            n >>= 1;
        }
        return ret;
    }
};