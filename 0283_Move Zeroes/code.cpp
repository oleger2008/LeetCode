// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]

// arr.size: [1..10^4]
// val: [-2^31..2^31 - 1]

//  r
//  l 
// [0,1,0,3,12]
//  if r on zero, then r go to find non-zero, then reassign left to what found right
// increase left if reassign happened

//  l r
// [1,1,0,3,12]

//    l r
// [1,1,0,3,12]

//    l   r
// [1,1,0,3,12]

//    l   r
// [1,3,0,3,12]
//    l   r
// [1,3,0,3,12]
//      l   r
// [1,3,0,3,12]
//      l    r
// [1,3,12,3,12]
//         l    r
// [1,3,12,3,12]
// r out of bound, so stop and from left reasign the rest on zero


// time: O(n)
// mem: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                ++right;
            } else {
                nums[left] = nums[right];
                ++left;
                ++right;
            }
        }
        while (left < nums.size()) {
            nums[left] = 0;
            ++left;
        }
    }
};