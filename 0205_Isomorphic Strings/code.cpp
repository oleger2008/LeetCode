// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true


// Constraints:
// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

// the idea is to have HashMap for both words
// scan both words and check in maps in containing

// time: O(n)
// mem: O(n) (but chars are only ascii so O(1))
class Solution {
public:
    // my naive
    // bool isIsomorphic(string s, string t) {
    //     std::unordered_map<char, char> s_map; s_map.reserve(256);
    //     std::unordered_map<char, char> t_map; t_map.reserve(256);
    //     for (int i = 0; i < s.size(); ++i) {
    //         if ((s_map.count(s[i]) && s_map[s[i]] != t[i]) ||
    //             (t_map.count(t[i]) && t_map[t[i]] != s[i]))
    //             return false;
    //         s_map[s[i]] = t[i];
    //         t_map[t[i]] = s[i];
    //     }
    //     return true;
    // }

    bool isIsomorphic(string s, string t) {
        std::array<int, 256> s_map = {};
        std::array<int, 256> t_map = {};
        for (int i = 0; i < s.size(); ++i) {
            if (s_map[s[i]] != t_map[t[i]])
                return false;
            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }
        return true;
    }
};

// trouble case
// s =
// "12"
// t =
// "\u0067\u0067"
