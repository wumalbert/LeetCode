class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;
        
        while (left <= right)
        {
            int middle = left + (right-left)/2;
            
            if (target == A[middle]) return true;
            
            if (A[left] < A[middle]) // the left part are sorted
            {
                if (target >= A[left] && target < A[middle])
                    right = middle-1;
                else
                    left = middle+1;
            }
            else if (A[left] > A[middle]) // the right part are sorted
            {
                if (target < A[middle] || target >= A[left])
                    right = middle-1;
                else
                    left = middle+1;
                
                /*
                if (target > A[middle] && target <= A[right])
                    left = middle+1;
                else
                    right = middle-1; */
            }
            else
            {
                for(++left; left < right && A[left] == A[left-1]; ++left);
            }
        }
        return false;
    }
};