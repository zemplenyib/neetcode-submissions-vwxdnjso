class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());
        if (nums.size() != seen.size()) return true;
        else return false;
    }
};