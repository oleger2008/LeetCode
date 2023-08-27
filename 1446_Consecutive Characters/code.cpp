// The power of the string is the maximum length of a non-empty substring that contains only one unique character.
// Given a string s, return the power of s.

// Example 1:
// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

// Example 2:
// Input: s = "abbcccddddeeeeedcba"
// Output: 5
// Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

// s.size(): [1..500]
// char: only lowercase eng

// "abbcccddddeeeeedcba"
// scan arr and fix curChar + count it + refresh maxCount
// time: O(n)
// mem: O(1)

// check:
// "a"
// "aaa"
// "abbb"
// "baaa"

class Solution {
public:
    int maxPower(string s) {
        int maxCount = 1;
        int count = 1;
        auto curChar = s[0];
        for (auto i = 1u; i < s.size(); ++i) {
            if (s[i] != curChar) {
                maxCount = std::max(maxCount, count);
                curChar = s[i];
                count = 1;
            } else {
                ++count;
            }
        }
        maxCount = std::max(maxCount, count);
        return maxCount;
    }
};