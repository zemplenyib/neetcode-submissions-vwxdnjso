class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i=0; i < nums.size(); ++i) {
            const int diff = target - nums[i];
            auto it = seen.find(diff);
            if (it != seen.end()) {
                return {it->second,i};
            }
            else {
                seen.insert({nums[i],i});
            }
        }
        return vector<int>();
    }
};
