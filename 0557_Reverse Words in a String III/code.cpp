// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Example 2:
// Input: s = "God Ding"
// Output: "doG gniD"

// str.size: [1...5*10^4]
// char: ASCII
// no leading trailing spaces
// at least one word in str
// separator = space

// main idea:
// 1. scan str on words
// 2. if took space then make swap for word begin, word end idxs

// time: O(N)
// mem: O(1)
class Solution {
public:
    string reverseWords(string s) {
        size_t begin = 0;
        size_t end = 0;
        const char space = ' ';
        const size_t size = s.size();
        for (int i = 0; i <= size; ++i) {
            if (i == size || s[i] == space) {
                end = i;
                reverse(s, begin, end);
                begin = i + 1;
            }
        }
        return s;
    }

private:
    void reverse(string& s, size_t begin, size_t end) {
        const size_t size = (end - begin) / 2;
        for (size_t i = 0; i < size; ++i) {
            std::swap(s[begin + i], s[end - i - 1]);
        }
    }
};