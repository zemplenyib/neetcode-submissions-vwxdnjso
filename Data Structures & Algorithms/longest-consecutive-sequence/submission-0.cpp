class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (auto n : st) {
            if (!st.contains(n-1)) {
                // Start of a sequence
                int next = ++n;
                int length = 1;
                while(st.contains(next)){ 
                    ++length;
                    ++next;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
