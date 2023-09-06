// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

// arr.size: [1..10^4]
// val: [-10^4..10^4]

//   l         r
// [-4,-1,0,3,10]
// arr[l] ^ 2 > arr[r] ^ 2 ? result.append(arr[l]) : result.append(arr[r])

// time: O(n)
// mem: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //       lr
        // |0 | 1|2|3|4 |5
        // [-4,-1,0,3,10]
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result;
        result.reserve(nums.size());
        while (left <= right) {
            if (std::abs(nums[left]) < std::abs(nums[right])) {
                result.push_back(nums[right] * nums[right]);
                --right;
            } else {
                result.push_back(nums[left] * nums[left]);
                ++left;
            }
        }
        std::reverse(begin(result), end(result));
        return result;
    }
};