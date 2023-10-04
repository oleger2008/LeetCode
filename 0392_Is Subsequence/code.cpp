// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not)

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

// s.size: [0..100]
// t.size: [0..10^4]
// char in s and t are lowercase eng

// idea: two pointers. if t[r] == s[l], then l++
// every step r++
// if l out of bound then true
// otherwise - false

//  l
// "abc"
//  r
// "ahbgdc"

//   l
// "abc"
//   r
// "ahbgdc"

//   l
// "abc"
//    r
// "ahbgdc"

//    l
// "abc"
//     r
// "ahbgdc"

//    l
// "abc"
//      r
// "ahbgdc"

//    l
// "abc"
//       r
// "ahbgdc"

//      l
// "abc"
//         r
// "ahbgdc"

// time: O(m + n)
// mem: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        while (left < s.size() && right < t.size()) {
            if (s[left] == t[right]) {
                ++left;
            }
            ++right;
        }
        if (left < s.size()) return false;
        return true;
    }
};