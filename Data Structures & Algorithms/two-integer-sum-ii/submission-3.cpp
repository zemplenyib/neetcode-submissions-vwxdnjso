class Solution {
public:
// Two pointer
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto l = numbers.begin();
        auto r = numbers.end() -1;

        while(*l+*r != target) {
            if (*l+*r < target) {
                ++l;
            }
            if (*l+*r > target) {
                --r;
            }
        }
        return {
            static_cast<int>(std::distance(numbers.begin(), l)) + 1,
            static_cast<int>(std::distance(numbers.begin(), r)) + 1
        };
    }
};
