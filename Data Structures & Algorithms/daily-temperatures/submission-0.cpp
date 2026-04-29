class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        res.reserve(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            int days = 0;
            int cnt = 0;
            for (int j = i+1; j < temperatures.size(); ++j) {
                ++cnt;
                if (temperatures[j] > temperatures[i]) {
                    days = cnt;
                    break;
                }
            }
            res.push_back(days);
        }
        return res;
    }
};
