class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // return hashSetSolution(nums, k);
        return slideWindowSolution(nums, k);
    }

    bool hashSetSolution(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_pos;
        const auto size = static_cast<int>(nums.size());
        num_to_pos.reserve(size);
        for (int i = 0; i < size; ++i) {
            const auto num = nums[i];
            const auto pos = num_to_pos.find(num);
            if ((pos != std::end(num_to_pos) && (i - pos->second <= k))) {
                return true;
            }
            num_to_pos[num] = i;
        }
        return false;
    }

    bool slideWindowSolution(vector<int>& nums, int k) {
        unordered_set<int> unique_nums;
        const auto window_size = k + 1;
        unique_nums.reserve(window_size);
        const auto size = static_cast<int>(nums.size());
        for (int i = 0, end = std::min(window_size, size); i < end; ++i) {
            const auto num = nums[i];
            if (unique_nums.count(num)) {
                return true;
            }
            unique_nums.insert(num);
        }
        for (int i = 0; i + window_size < size; ++i) {
            const auto left = nums[i];
            unique_nums.erase(left);
            const auto right = nums[i + window_size];
            if (unique_nums.count(right)) {
                return true;
            }
            unique_nums.insert(right);
        }
        return false;
    }
};