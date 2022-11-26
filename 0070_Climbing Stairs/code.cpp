class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.reserve(n);
        dp.push_back(1);
        dp.push_back(2);
        
        for (size_t i = 2; i < n; ++i) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        
        return dp[n - 1];
    }
};