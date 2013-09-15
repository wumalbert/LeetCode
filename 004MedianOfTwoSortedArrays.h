class Solution {
private:
    double median(int A[], int m)
    {
        if (m <= 0) return 0; //empty array
        
        if (m & 0x1) return A[m/2]; // odd array
        else return (A[m/2-1] + A[m/2]) / 2.0; //even array
        
    }
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // empty aray
        if (m <= 0 && n <= 0) return 0;
        if (m <= 0) return median(B, n);
        if (n <= 0) return median(A, m);
        
        // the odd flag: true, odd; false, even
        bool odd = (m + n) & 0x1;
        int k = (m + n + 1) >> 1;
        
        int left1, right1, k1, left2, right2, k2;
        left1 = left2 = 0;
        right1 = m;
        right2 = n;
        
        double result;
        // locate the kth number
        while(left1 < right1 && left2 < right2)
        {
            if (1 == k)
            {
                if (A[left1] < B[left2])
                {
                    result = A[left1];
                    left1 += k;
                    m -= k;
                    k = 0;
                }
                else
                {
                    result = B[left2];
                    left2 += k;
                    n -= k;
                    k = 0;
                }
                break;
            }
            
            k1 = k / 2;
            k2 = k - k1;
            if (k1 > m)
            {
                k1 = m;
                k2 = k - k1;
            }
            if (k2 > n)
            {
                k2 = n;
                k1 = k - k2;
            }
            
            if (A[left1+k1-1] == B[left2+k2-1])
            {
                result = A[left1+k1-1];
                left1 += k1;
                m -= k1;
                k -= k1;
                left2 += k2;
                n -= k2;
                k -= k2;
                break;
            }
            else if (A[left1+k1-1] < B[left2+k2-1])
            {
                left1 += k1;
                m -= k1;
                k -= k1;
            }
            else 
            {
                left2 += k2;
                n -= k2;
                k -= k2;
            }
        }
        
        // there is empty array
        if (k > 0)
        {
            if (left1 < right1)
            {
                result = A[left1+k-1];
                left1 += k;
                m -= k;
                k = 0;
            }
            else
            {
                result = B[left2+k-1];
                left2 += k;
                n -= k;
                k = 0;
            }
        }
        
        // handle the even case
        if (!odd)
        {
            if (left1 >= right1)
            {
                result = (result + B[left2]) / 2.0;
            }
            else if (left2 >= right2)
            {
                result = (result + A[left1]) / 2.0;
            }
            else
            {
                if (A[left1] < B[left2]) result = (result + A[left1]) / 2.0;
                else result = (result + B[left2]) / 2.0;
            }
        }
        
        return result;
    }
};