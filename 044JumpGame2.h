#include <vector>

using namespace std;
class Solution {
public:
    int jump01(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!A || 0 == n) return 0;
        
        // dynamic programming  
        vector<int> step(n, numeric_limits<int>::max());
        step[0] = 0;
        
        for (int i = 0; i < n-1; ++i)
        {
            // for (int j = i > A[i] ? i-A[i] : 0; j <= A[i] && i+j < n; ++j)
            for (int j = 1; j <= A[i] && i+j < n; ++j)
            {
                if (step[i] + 1 < step[i+j])
                {
                    step[i+j] = step[i] + 1;
                    if(i+j == n-1) return step[n-1];
                }
            }
        }
        
        return step[n-1];
    }

    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int last = 0;
        int curr = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i > last)
            {
                last = curr;
                ++ret;

                if (last >= n-1) return ret;
            }

            curr = max(curr, i + A[i]);
        }
    }
};