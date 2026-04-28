class Solution {
public:
// Binary search
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto it = numbers.begin();
        while (it != numbers.end()) {
            int val = target-*it;
            int l = std::distance(numbers.begin(), it) + 1;
            int r = numbers.size() - 1;
            while(l <= r) {
                int mid = l + static_cast<int>((r-l)/2);
                if (numbers[mid] == val) {
                    int idx1 = std::distance(numbers.begin(), it);
                    return {idx1+1, mid+1};
                }
                if (numbers[mid] < val) {
                    l = mid + 1;
                }
                if (val < numbers[mid]) {
                    r = mid - 1;
                }
            }
            ++it;
        }
        return {0,0};
    }
};
