// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

// str.size: [1..10^5]
// char: only lowercase eng

// usedDelete = false
//  l  r 
// "abca"
// a == a, move l,r

// usedDelete = false
//   lr 
// "abca"
// b != c, usedDelete => true, move r

// usedDelete = true
//   r
//   l 
// "abca"
// l == r, so stop, return true

// ---------

// usedDelete = false
//  l    r 
// "abnfca"
// a == a, move l,r

// usedDelete = false
//   l  r 
// "abnfca"
// b != c, usedDelete => true, move r

// usedDelete = false
//   l r 
// "abnfca"
// b ! f, usedDelete is already true, so return false

// time: O(n)
// mem: O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        return checkLeft(s) || checkRight(s);
    }

    bool checkRight(string_view s) {
        bool usedDelete = false;
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (!usedDelete) {
                    usedDelete = true;
                    --right;
                    continue;
                } else {
                    return false;
                }
            }
            ++left;
            --right;
        }
        return true;
    }

    bool checkLeft(string_view s) {
        bool usedDelete = false;
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (!usedDelete) {
                    usedDelete = true;
                    ++left;
                    continue;
                } else {
                    return false;
                }
            }
            ++left;
            --right;
        }
        return true;
    }
};