// Given a string s, find the length of the longest 
// substring  without repeating characters.

 
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// str.size: [0..5*10^4]
// char: eng letters, digits, symbols, spaces

// can use dict [ket = char, val = pos in str]
// scaning str check dict on repeat: if has repeat than take 
// pos of repeated char and move slide window begin

//  r
//  l
// |0|1|2|3|4|5|6|7|8 
// [a,b,c,a,b,c,b,b]
// [[a,0]]

//    r
//  l
// |0|1|2|3|4|5|6|7|8 
// [a,b,c,a,b,c,b,b]
// [[a,0],[b,1]]

//      r
//  l
// |0|1|2|3|4|5|6|7|8 
// [a,b,c,a,b,c,b,b]
// [[a,0],[b,1],[c,2]]

//        r
//  l
// |0|1|2|3|4|5|6|7|8 
// [a,b,c,a,b,c,b,b]
// [[a,0],[b,1],[c,2]]
// str[r] == a, which is repeat, so l = dict[a] + 1
// after moving l, dict[a] = r 

// on every step refresh max(r - l)
// stop cycle when r is out of bound

// time: O(N)
// mem: O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //        r
        //      l
        // |0|1|2|3|4|5|6|7|8 
        // [a,b,b,a]
        
        std::unordered_map<char, int> char_to_pos; // [[a,0],[b,2]]
        int result = 0; // result = 2
        int left = 0; // left = 2
        int right = 0; // right = 2
        while (right < s.size()) { // 3 < 4
            auto cur = s[right]; // cur = 'a'
            if (char_to_pos.count(cur)) { // 1
                left = std::max(left, char_to_pos[cur] + 1); // left = max(2, 0 + 1)
            }
            char_to_pos[cur] = right; // [b,2]
            ++right; // right = 3
            result = std::max(result, right - left); // max(3 - 2, 1) -> 2
        }
        return result;
    }
};