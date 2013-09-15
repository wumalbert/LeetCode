bool myCompare(pair<int, int> number1, pair<int, int> number2)
{
    return number1.first < number2.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector< pair<int, int> > numberIndexPairs;
        for (vector<int>::size_type i = 0, i < numbers.size(); ++i)
        {
            numberIndexPairs.push_back(make_pair(numbers[i], i));
        }
        
        sort(numberIndexPairs.begin(), numberIndexPairs.end(), myCompare);
        
        vector< pair<int, int> >::size_type left, right;
        left = 0;
        right = numberIndexPairs.size()-1;
        int sum = 0;
        while(left < right)
        {
            sum = numberIndexPairs[left].first + numberIndexPairs[right].first;
            if (sum == target) break;
            else if (sum < target) ++left;
            else --right;
        }
        
        if (left < right)
        {
            if (numberIndexPairs[left].second < numberIndexPairs[right].second)
            {
                result.push_back(numberIndexPairs[left].second + 1);
                result.push_back(numberIndexPairs[right].second + 1);
            }
            else
            {
                result.push_back(numberIndexPairs[right].second + 1);
                result.push_back(numberIndexPairs[left].second + 1);
            }
        }
        
        return result;
    }
};