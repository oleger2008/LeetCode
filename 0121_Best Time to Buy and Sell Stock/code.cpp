class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int profit = 0;
        int buy = std::numeric_limits<int>::max();
        for (const auto price : prices) {
            buy = min(buy, price);
            profit = max(profit, price - buy);
        }
        
        return profit;
    }
};