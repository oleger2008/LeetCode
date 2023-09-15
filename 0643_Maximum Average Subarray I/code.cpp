// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

// arr.size: [1..10^5]
// value: [-10^4..10^4]
// k: [1..10^5]
// k <= n

// k = 4
// [1+12+-5+-6]
// [1,12,-5,-6,50,3]
// sum4 = 2
// avg = 2/4 = 0.5

//   [12+-5+-6+50]
// [1,12,-5,-6,50,3]
// after shift we can see that sum4 changed only on border elements
// so no need to recalc sum, only sub first and add new last

// while scaning array, refresh result

// time: O(N)
// mem: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //i|0|1|2|3|4|5
        // [0,4,0,3,2]
        // k = 1
        int sum = std::accumulate(std::begin(nums), std::begin(nums) + k, 0);
        int cur = sum;
        for (int i = k; i < nums.size(); ++i) {
            cur = cur - nums[i - k] + nums[i];
            sum = std::max(sum, cur);
        }
        return static_cast<double>(sum) / k;
    }
};