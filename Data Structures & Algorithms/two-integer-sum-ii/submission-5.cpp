class Solution {
public:
// Hashmap
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> mp;
        for (auto& n : numbers) {
            auto it = mp.find(target-n);
            if (it != mp.end()) {
                int idx1 = it->second;
                int idx2 = &n - &numbers[0] + 1;
                return {idx1, idx2};
            } else {
                mp[n] = &n - &numbers[0] + 1;
            }
        }
    }
};
