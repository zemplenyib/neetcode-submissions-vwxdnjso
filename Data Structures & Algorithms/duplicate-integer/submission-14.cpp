class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (auto n : nums) {
            auto[_,found] = seen.insert(n);
            if (!found) {
                return true;
            }                
        }
        return false;
    }
};