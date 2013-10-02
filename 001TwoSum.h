bool myComp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
class Solution01 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (numbers.size() < 2) return ret;
        
        vector<pair<int, int> > numberIndexs(numbers.size(), pair<int, int>(0, 0));
        vector<pair<int, int> >::iterator left = numberIndexs.begin();
        for(vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
        {
            left->first = *i;
            left->second = i - numbers.begin() + 1;
            ++left;
        }
        
        sort(numberIndexs.begin(), numberIndexs.end(), myComp);
        
        left = numberIndexs.begin();
        vector<pair<int, int> >::iterator right = numberIndexs.end() - 1;
        while (left < right)
        {
            if (left->first + right->first == target)
            {
                if (left->second < right->second)
                {
                    ret.push_back(left->second);
                    ret.push_back(right->second);
                }
                else
                {
                    ret.push_back(right->second);
                    ret.push_back(left->second);
                }
                return ret;
            }
            else if(left->first + right->first < target)
                ++left;
            else --right;
        }
        
        return ret;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (numbers.size() < 2) return ret;
        
        map<int, int> numberMap;
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numberMap.find(numbers[i]) == numberMap.end())
            {
                numberMap[target - numbers[i]] = i+1;
            }
            else
            {
                ret.push_back(numberMap[numbers[i]]);
                ret.push_back(i+1);
                break;
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};