class Solution {
public:
    int maxProfit(vector<int>& prices) {
        optional<int> buy_;
        optional<int> sell_;
        
        int profit = 0; // 7
        for (const auto price : prices) {
            if ((!buy_ || (price < buy_)) && !sell_) {
                buy_ = price;
                continue;
            }

            if (!sell_ || (price > sell_)) {
                sell_ = price;
            } else if (sell_.has_value() && (price < sell_)) {
                profit += (*sell_ - *buy_);
                buy_ = price;
                sell_.reset();
            }
        }

        if (sell_ > buy_) {
            profit += (*sell_ - *buy_);
        }

        return profit;
    }
};