// You are given two integer arrays nums1 and nums2,
// sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function,
// but instead be stored inside the array nums1. To accommodate this,
// nums1 has a length of m + n, where the first m elements denote the
// elements that should be merged, and the last n elements are set to 0
// and should be ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// m, n?: 0 <= m, n <= 200
// 1 <= m + n <= 200
// val in nums1, nums2: [-10^9..10^9]

// third example
//      l                m
// [6,6,10,0,0,0,0,0,0,0,0]
//                  r
// [2,5,6,7,8,9,10,11]

//      l              m
// [6,6,10,0,0,0,0,0,0,0,11]
//               r
// [2,5,6,7,8,9,10,0]

//      l            m
// [6,6,10,0,0,0,0,0,0,10,11]
//            r
// [2,5,6,7,8,9,0,0]

//    l           m
// [6,6,0,0,0,0,0,0,10,10,11]
//            r
// [2,5,6,7,8,9,0,0]

//    l         m
// [6,6,0,0,0,0,0,9,10,10,11]
//          r
// [2,5,6,7,8,0,0,0]

//    l       m
// [6,6,0,0,0,0,8,9,10,10,11]
//        r
// [2,5,6,7,0,0,0,0]

//    l     m
// [6,6,0,0,0,7,8,9,10,10,11]
//      r
// [2,5,6,0,0,0,0,0]

//    l   m
// [6,6,0,0,6,7,8,9,10,10,11]
//    r
// [2,5,0,0,0,0,0,0]

//  l   m
// [6,0,0,6,6,7,8,9,10,10,11]
//    r
// [2,5,0,0,0,0,0,0]

//l   m
// [0,0,6,6,6,7,8,9,10,10,11]
//    r
// [2,5,0,0,0,0,0,0]

//-------
//      l       m
// [1,2,3,0,0,0,0]
//        r
// [4,5,6,7]

// time: O(n + m)
// mem: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //        0,1,2,3,4,5
        // nums1 [0]
        // nums2 [1]
        int left = m - 1; // 0
        int cur = m + n - 1; // 0
        int right = n - 1; // 0
        while ((left >= 0) && (right >= 0)) {
            nums1[cur--] = (nums1[left] > nums2[right])
                ? nums1[left--] 
                : nums2[right--];
        }
        while (right >= 0) {
            nums1[cur--] = nums2[right--];
        }
    }
};