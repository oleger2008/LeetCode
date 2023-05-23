class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique_nums;
        unique_nums.reserve(nums.size());
        for (const auto num : nums) {
            if (unique_nums.count(num)) {
                return true;
            }
            unique_nums.insert(num);
        }
        return false;
    }
};