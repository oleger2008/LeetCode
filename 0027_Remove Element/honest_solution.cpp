class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const auto size = nums.size();
        size_t left = 0u;
        while (left != size && nums[left] != val) {
            ++left;
        }
        if (left == size) {
            return left;
        }

        size_t right = left;
        while (right != size && nums[right] == val) {
            ++right;
        }
        if (right == size) {
            return left;
        }

        while (true) {
            std::swap(nums[left], nums[right]);
            if (nums[left] != val) {
                while (left != size && nums[left] != val) {
                    ++left;
                }
                if (left == size) {
                    return left;
                }
            }
            if (nums[right] == val) {
                while (right != size && nums[right] == val) {
                    ++right;
                }
                if (right == size) {
                    return left;
                }
            }
        }
        return left;
    }
};