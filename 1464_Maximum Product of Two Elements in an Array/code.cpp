// Given the array of integers nums, you will choose two different indices i and j of that array. 
// Return the maximum value of (nums[i]-1)*(nums[j]-1).

// Example 1:
// Input: nums = [3,4,5,2]
// Output: 12 
// Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

// Example 2:
// Input: nums = [1,5,4,5]
// Output: 16
// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

// Example 3:
// Input: nums = [3,7]
// Output: 12

// arr.size: [2..500]
// value: [1, 10^3]

// dict [key: left.value, value: dict[key: right.value, value: multiply]] -> went to failt O(1) memory
// scan array: find idx with max value, then find idx of second max value
//  l     r
// [3,4,5,2]
// multiply = 2

// time: O(N)
// memory: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t first_max_idx = 0;
        const size_t size = nums.size();
        for (size_t i = 1u; i < size; ++i) {
            if (nums[i] > nums[first_max_idx]) { 
                first_max_idx = i;
            }
        }
        size_t second_max_idx = (first_max_idx == 0) ? 1 : 0;
        for (size_t i = 1u; i < size; ++i) {
            if (i == first_max_idx) {
                continue;
            }
            if (nums[i] > nums[second_max_idx]) {
                second_max_idx = i;
            }
        }
        return (nums[second_max_idx] - 1) * (nums[first_max_idx] - 1);
    }
};