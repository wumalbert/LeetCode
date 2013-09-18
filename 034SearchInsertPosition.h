class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;
        
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(target == A[middle]) return middle;
            
            if (target < A[middle]) right = middle-1;
            else left = middle+1;
        }
        
        return left;
    }
};