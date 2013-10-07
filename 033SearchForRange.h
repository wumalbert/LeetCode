class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        int left = 0, right = n-1;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            if (target == A[middle]) {
                if (0 == middle || (middle > 0 && A[middle] != A[middle-1])) {
                    ret.push_back(middle);
                    break;
                } else {
                    right = middle-1;
                }
            } else if (target < A[middle]) {
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
        if (ret.empty()) ret.push_back(-1);
        left = 0, right = n-1;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            if (target == A[middle]) {
                if (n-1 == middle || (middle < n-1 && A[middle] != A[middle+1])) {
                    ret.push_back(middle);
                    break;
                } else {
                    left = middle+1;
                }
            } else if (target < A[middle]) {
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
        if (ret.size() < 2) ret.push_back(-1);
        return ret;
    }
};
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret(2, -1);
        int left = 0, right = n-1;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            if (A[middle] >= target) {
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
        if (A[left] == target) ret[0] = ret[1] = left;
        right = n-1;
        while (left <= right) {
            int middle = left + ((right-left) >> 1);
            if (A[middle] > target) {
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
        if (A[right] == target) ret[1] = right;
        return ret;
    }
};