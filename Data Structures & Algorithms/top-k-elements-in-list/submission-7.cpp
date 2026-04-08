class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> dict;
        std::vector<std::vector<int>> freq(nums.size() + 1);
        for (auto n : nums) {
            dict[n]++;
        }

        for (const auto& [num, fr] : dict) {
            freq[fr].push_back(num);
        }

        std::vector<int> out;
        for (int i = freq.size() - 1; i >= 0 ; --i) {
            for (auto n : freq[i]) {
                out.push_back(n);
                if (out.size() == k) return out;
            }
        }
        return out;
    }
};
