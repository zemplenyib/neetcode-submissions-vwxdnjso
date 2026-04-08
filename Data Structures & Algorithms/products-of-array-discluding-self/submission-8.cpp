class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);

        for (int i = 1; i < out.size(); ++i) {
            out[i] = out[i-1] * nums[i-1];
        }

        int postfix = nums.back();
        for (int i = out.size() - 2; i > -1; --i) {
            out[i] = out[i] * postfix;
            postfix *= nums[i];
        }

        return out;
    }
};
