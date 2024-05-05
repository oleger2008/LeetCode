// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// arr.size: [1..5000]0
// val, target: [-10^4..10^4]
// all nums r unique
// arr is ascending (possibly rotated)

// 1. bin search offset
// 2. bin search target but including offset in idxes

// I. isGood for offset search:
// edges shoud be like this: left > right,
// because ordered array is offseted (if no offset then left < right)
// so isGood checks: left <= cur > right
// 2. ans in right, so left = -1, right = arr.size - 1

// [4,5,6,7,0,1,2]
// |0|1|2|3|4|5|6|7
// |t|t|t|t|f|f|f|


// II. isGood for target: cur <= target
// but index should use offset: curIdx = (i + offset) % arr.size
// ans in left, so left = 0; right = arr.size
// and ans should use offset

// time: O(logN)
// mem: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int offset = searchOffset(nums);
        int left = 0;
        int right = nums.size();
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (targetComp(nums[(mid + offset) % nums.size()], target)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int result = (left + offset) % nums.size();
        return nums[result] == target ? result : -1;
    }

private:
    bool targetComp(int val, int target) {
        return val <= target;
    }

    bool offsetComp(int left, int cur, int right) {
        return (left <= cur) && (cur > right);
    }

    int searchOffset(vector<int>& nums) {
        int left = -1;
        int right = nums.size() - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (offsetComp(nums.front(), nums[mid], nums.back())) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};