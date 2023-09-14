// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// chars: any ASCII printable
// for palindrome: alpha(lowercase) + numeric
// str.size: [1, 2*10^5]

// [a, b, \s, o, \s, \t, b, \s, a]
// expect: true
// two pointer, skip any non alphanumeric

//  l                           r
// [a, b, \s, o, \s, \t, b, \s, a]
// l == r, so move them

//     l                     r
// [a, b, \s, o, \s, \t, b, \s, a]
// r is non alphanumeric, move it

//     l                 r
// [a, b, \s, o, \s, \t, b, \s, a]
// l == r, move them

//        l           r
// [a, b, \s, o, \s, \t, b, \s, a]
// l is non alphanumeric, move it

//            l       r
// [a, b, \s, o, \s, \t, b, \s, a]
// r is non alphanumeric, move it

//            l   r
// [a, b, \s, o, \s, \t, b, \s, a]
// r is non alphanumeric, move it

//            lr
// [a, b, \s, o, \s, \t, b, \s, a]
// r is non alphanumeric, move it
// l == r

//         r     l
// [a, b, \s, o, \s, \t, b, \s, a]
// l > r, so quit and return true

// time: O(n)
// mem: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (!isAplphaNumeric(s[left])) {
                ++left;
                continue;
            }
            if (!isAplphaNumeric(s[right])) {
                --right;
                continue;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

private:
    bool isAplphaNumeric(char c) {
        return std::isalpha(c) || std::isdigit(c);
    }
};