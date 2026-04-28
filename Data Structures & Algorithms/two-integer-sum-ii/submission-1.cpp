class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto it1 = numbers.begin();
        while(it1 != numbers.end()) {
            auto it2 = it1 + 1;
            while(it2 != numbers.end() && *it2 < target - *it1) {
                ++it2;
            }
            if (*it2 == target - *it1) {
                 return {
                    static_cast<int>(std::distance(numbers.begin(), it1))+1,
                    static_cast<int>(std::distance(numbers.begin(), it2))+1
                 };
            }

            ++it1;
        }
        return {0,0};
    }
};
