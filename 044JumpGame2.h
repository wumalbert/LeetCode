using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A || 0 == n) return 0;
        // dynamic programming  
        vector<int> step(n, numeric_limits<int>::max());
        step[0] = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 1; j <= A[i] && i+j < n; ++j) {
                if (step[i] + 1 < step[i+j]) {
                    step[i+j] = step[i] + 1;
                    if(i+j == n-1) return step[n-1];
                }
            }
        }
        return step[n-1];
    }
};
class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!A || n < 1) return -1;
        if (1 == n) return 0;
        int previous_reach = 0, next_reach = 0, steps = 0;
        for (int i = 0; i <= previous_reach; ++i) {
            next_reach = max(i+A[i], next_reach);
            if (next_reach >= n-1) return steps+1;
            if (i == previous_reach) {
                ++steps;
                previous_reach = next_reach;
            }
        }
        return -1;
    }
};