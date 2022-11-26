class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        const auto size = nums.size();
        for (size_t i = 0u; i < size; ++i) {
            const auto idx = static_cast<size_t>(abs(nums[i]) - 1);
            if (nums[idx] > 0) {
                nums[idx] *= (-1);
            }
        }
        for (size_t i = 0u; i < size; ++i) {
            if (nums[i] > 0) {
                result.push_back(static_cast<int>(i + 1u));
            }
        }
        return result;
    }
};