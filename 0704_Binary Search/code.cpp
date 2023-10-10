// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

// arr.size: [1..10^4]
// value, target: [-10^4...10^4]
// all nums are unique
// arr is sorted in ascending order

// strategy:
// 1. what is comp func?
// 2. use it on arr to have true/false or false/true chain
// 3. use tree ptr: left, mid, right
// 4. decide whether left or right would contain answer, whether would be out of bound

// comp(i): arr[i] <= target(2)
//         m
//                r 
//   l
// |0 |1|2|3|4|5 |6
// [-1,0,3,5,9,12]
// |t |t|t|f|f|f |
// arr[m] > target, so go to left half

// comp(i): arr[i] <= target(2)
//     m
//         r 
//   l
// |0 |1|2|3|4|5 |6
// [-1,0,3,5,9,12]
// |t |t|t| | |  |
// arr[m] < target, so go to right half

// comp(i): arr[i] <= target(2)
//       m
//         r 
//     l
// |0 |1|2|3|4|5 |6
// [-1,0,3,5,9,12]
// |  |t|t| | |  |
// arr[m] <= target, so go to right half

// comp(i): arr[i] <= target(2)
//       m
//         r 
//       l
// |0 |1|2|3|4|5 |6
// [-1,0,3,5,9,12]
// |  | |t| | |  |
// m == l, return l ?

// time: O(log(n))
// mem: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end();
        while (right - left > 1) {
            auto mid = left + (right - left) / 2;
            if (comp(*mid, target)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return *left == target ? static_cast<int>(left - nums.begin()) : -1;

        // int left = 0;
        // int right = nums.size();
        // while (left + 1 != right) {
        //     int mid = left + (right - left) / 2;
        //     if (comp(nums[mid], target)) {
        //         left = mid;
        //     } else {
        //         right = mid;
        //     }
        // }
        // return nums[left] == target ? left : -1;
    }

private:
    bool comp(int num, int target) {
        return num <= target;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto begin = nums.begin();
//         auto mid = begin + (nums.size() / 2);
//         auto end = nums.end();
        
//         while (target != *mid) {
//             if (target < *mid) {
//                 // begin is same
//                 end = mid;
//             } else if (target > *mid) {
//                 begin = mid + 1;
//                 // end is same
//             }
//             if (begin == end) {
//                 return -1;
//             }
//             mid = begin + distance(begin, end) / 2;
//         }
//         return distance(nums.begin(), mid);
//     }
// };