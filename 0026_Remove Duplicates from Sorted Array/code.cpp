// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:
// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length
// int k = removeDuplicates(nums); // Calls your implementation
// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// arr.size: [1..3*10^4]
// val: [-100..100]
// non-decreasing order


//  l
//  r
// [0,0,1,1,1,2,2,3,3,4]

//  l
//    r
// [0,0,1,1,1,2,2,3,3,4]
// found duplicate

//  l
//      r
// [0,0,1,1,1,2,2,3,3,4]
// find end of duplicates

//  l
//      r
// [0,0,1,1,1,2,2,3,3,4]
// reassign r to l + 1

//  l
//      r
// [0,1,1,1,1,2,2,3,3,4]
// move l

//    l
//      r
// [0,1,1,1,1,2,2,3,3,4]
// repeat steps

//    l
//            r
// [0,1,1,1,1,2,2,3,3,4]

//      l
//            r
// [0,1,2,1,1,2,2,3,3,4]

//      l
//                r
// [0,1,2,3,1,2,2,3,3,4]

//        l
//                r
// [0,1,2,3,1,2,2,3,3,4]

//        l
//                    r
// [0,1,2,3,1,2,2,3,3,4]

//        l
//                    r
// [0,1,2,3,4,2,2,3,3,4]

// imagine if its one more num
//          l
//                    r
// [0,1,2,3,4,2,2,3,3,4,5]

//          l
//                      r
// [0,1,2,3,4,2,2,3,3,4,5]

//            l
//                        r
// [0,1,2,3,4,5,2,3,3,4,5]


// time: O(n)
// mem: O(1)
class Solution {
public: 
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        while (right < nums.size()) {
            if (nums[right] != nums[left]) {
                nums[left + 1] = nums[right];
                ++left;
            }
            ++right;
        }
        return left + 1;
    }
};