// Description
// Given two strings S and T, determine if they are both one edit distance apart.
// One edit distance means doing one of these operation:
// insert one character in any position of S
// delete one character in S
// change any one character in S to other character

// Example 1:
// Input: s = "aDb", t = "adb"
// Output: true

// Example 2:
// Input: s = "ab", t = "ab"
// Output: false
// Explanation:
// s=t ,so they aren't one edit distance apart

// two ptrs
// the thing is that we can move ptr in case: delete/insert/change
// delete: move ptr of bigger str
// insert: move ptr of smaller one
// change: move both ptrs
// if we on edit case secondly that it's false
// if no one of edit is used it's also false
// if one of them used - true

// arr.size: ?
// char: ?

// time: O(n)
// mem: O(1)
class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        if (int lhs = static_cast<int>(s.size()),
            rhs = static_cast<int>(t.size());
            std::abs(lhs - rhs) > 1) {
            return false;
        }
        if (s.empty() || t.empty()) return true;

        int left = 0;
        int right = 0;
        auto ins = [&right]() { ++right; };
        auto del = [&left]() { ++left; };
        auto chg = [&left, &right]() { ++left; ++right; };

        bool useEdit = false;
        while (left < s.size() && right < s.size()) {
            if (s[left] == t[right]) {
                ++left;
                ++right;
                continue;
            }
            if (useEdit) return false;
            useEdit = true;
            if (s.size() < t.size()) {
                ins();
            } else if (s.size() > t.size()) {
                del();
            } else {
                chg();
            }
        }

        return useEdit;
    }
};