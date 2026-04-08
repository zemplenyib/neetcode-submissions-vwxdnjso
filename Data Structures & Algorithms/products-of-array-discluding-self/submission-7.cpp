class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
         vector<int> prefix(n, 1);
         vector<int> postfix(n, 1);
         vector<int> out(n);

         for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = prefix[i-1] * nums[i-1];
         }

         for (int i = postfix.size() - 2; i > -1; --i) {
            postfix[i] = postfix[i+1] * nums[i+1];
         }

         for (int i = 0; i < out.size(); ++i) {
            out[i] = prefix[i] * postfix[i];
         }

         return out;
    }
};
