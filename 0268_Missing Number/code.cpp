class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const auto size = static_cast<int>(nums.size());
        const int expected_sum = size * (size + 1) / 2;
        const auto nums_sum = accumulate(nums.begin(), nums.end(), 0);
        return expected_sum - nums_sum;
    }
};