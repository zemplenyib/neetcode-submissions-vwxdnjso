class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int cheapest = prices[0];
        int profit = 0;
        for (int i = 0; i < n; ++i) {
            cheapest = std::min(cheapest, prices[i]);
            profit = std::max(profit, prices[i] - cheapest);
        }
        return profit;
    }
};
