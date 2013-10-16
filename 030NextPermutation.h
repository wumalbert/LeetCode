class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (num.size() < 2) return;
        int first_decrease = num.size()-2; // find first decrease index
        while (first_decrease >= 0 && num[first_decrease] >= num[first_decrease+1]) --first_decrease;
        if (first_decrease < 0) {
            reverse(num.begin(), num.end()-1);
            return;
        }
        int first_larger = num.size()-1;
        while (first_larger > first_decrease && num[first_larger] <= num[first_decrease]) --first_larger;
        swap(num.begin() + first_decrease, num.begin() + first_larger);
        reverse(num.begin()+first_decrease+1, num.end()-1);
    }
private:
    void swap(vector<int>::iterator a, vector<int>::iterator b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
        while (begin < end) swap(begin++, end--);
    }
};