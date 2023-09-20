// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// arr.size: [1..10^4]
// str.size: [0..100]
// char: eng lowercase

// use hashmap where key is sorted str
// then return hashmap -> vec<vec<str>>

// []
//    i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat"]}, ]
//    i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat", "tea"]}, ]
//           i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat", "tea"]}, {"ant": ["tan"]}]
//                 i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat", "tea", "ate"]}, {"ant": ["tan"]}]
//                      i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat", "tea", "ate"]}, {"ant": ["tan", "nat"]}]
//                            i
// ["eat","tea","tan","ate","nat","bat"]

// [{"eat": ["eat", "tea", "ate"]}, {"ant": ["tan", "nat"]}, {"abt": ["bat"]}]
//                                  i
// ["eat","tea","tan","ate","nat","bat"]

// return: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]

// time: O(n), where n - chars count
// mem: O(n), because need to form answer
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string_view> > strings;
        for (const auto &s : strs) {
            auto key = s;
            std::sort(std::begin(key), std::end(key));
            strings[key].emplace_back(s);
        }
        vector<vector<string>> result;
        result.reserve(strings.size());
        for (const auto &[_, vec] : strings) {
            result.emplace_back(vec.begin(), vec.end());
        }
        return result;
    }
};