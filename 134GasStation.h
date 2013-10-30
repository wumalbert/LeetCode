class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (gas.empty()) return -1;
        int n = gas.size();
        vector<int> remainder(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            remainder[i] = remainder[i-1] + gas[i-1] - cost[i-1];
        }
        for (int start = 0, current = 0; start < n; ++start) {
            for (current = 0; current < start; ++current)
                if (remainder[n] - remainder[start] + remainder[current+1] < 0) break;
            if (current < start) continue;
            for (; current < n; ++current)
                if (remainder[current+1] - remainder[start] < 0) break;
            if (current == n) return start;
        }
        return -1;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (gas.empty()) return -1;
        int remainder = 0, total_remainder = 0, start = -1;
        for (int i = 0; i < gas.size(); ++i) {
            remainder += gas[i] - cost[i];
            total_remainder += gas[i] - cost[i];
            if (remainder < 0) {
                start = i;
                remainder = 0;
            }
        }
        return total_remainder >= 0 ? start+1 : -1;
    }
};