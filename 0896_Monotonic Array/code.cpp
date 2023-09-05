// An array is monotonic if it is either monotone increasing or monotone decreasing.
// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
// An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

// Example 2:
// Input: nums = [6,5,4,4]
// Output: true

// Example 3:
// Input: nums = [1,3,2]
// Output: false

// arr.size: [1..10^5]
// val: [-10^5..10^5]

// time: O(n)
// mem: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const size_t size = nums.size();
        bool isInc = true;
        bool isDec = true;
        for (size_t i = 1u; i < size; ++i) {
            isInc = isInc && (nums[i] >= nums[i - 1]);
            isDec = isDec && (nums[i] <= nums[i - 1]);
        }
        return isInc || isDec;
    }
};