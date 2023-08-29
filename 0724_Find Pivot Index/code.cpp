// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to
// the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because
// there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

// arr.size(): [1, 10^4]
// val: [-1000, 1000]

// v1: prefix sum
// traverse over prefix_sum array and check sum(l, pivot) == sum(pivot, r)
// time: O(n)
// mem: O(n)

// v2: accumulate array to have total sum
// the thing is that sum left + pivot + sum right == total sum
// it fits to asking about the leftes one pivot
// because we will traverse from left
// time: O(n)
// mem: O(1)

// check
// [2,1,-1]
// [1,-1, 2]
// [1,2,3]
// [1]

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = std::accumulate(std::begin(nums), std::end(nums), 0);
        const int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (leftSum == (rightSum - nums[i])) {
                return i;
            }
            leftSum += nums[i];
            rightSum -= nums[i];
        }
        return -1;
    }
};