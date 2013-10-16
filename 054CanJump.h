class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int reach = 0;
        for (int i = 0; i <= reach && reach < n-1; ++i) {
            reach = max(reach, A[i]+i);
        }
        return reach >= n-1;
    }
};
class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A || n < 1) return false;
        if (1 == n) return true;
        int farthest = A[0];
        for (int i = 1; i <= farthest; ++i) {
            farthest = max(farthest, i + A[i]);
            if (farthest >= n-1) return true;
        }
        return false;
    }
};