class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fullProd = 1;
        vector<int> zeros;
        vector<int> out(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                fullProd *= nums[i];
            } else {
                zeros.push_back(i);
            }
        }
        
        if (zeros.size() > 1) {
            return out;
        }

        if (zeros.size() == 1) {
            out[zeros[0]] = fullProd;
            return out;
        }

        for (int i = 0; i < out.size(); ++i) {
            out[i] = fullProd / nums[i];
        }

        return out;
    }
};
