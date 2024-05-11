class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); ++i) {
            if (ch == word[i]) {
                reverse(word, i + 1);
                break;
            }
        }
        return word;
    }

    void reverse(string &word, int end) {
        for (int i = 0; i < end / 2; ++i) {
            std::swap(word[i], word[end - 1 - i]);
        }
    }
};

// abcdefd, ch = "d"

//    i
// 01234567
// abcdefd

//     e
// abcdefd

// 1. найти первый символ равный ch
// 2. стандартный реверс на подстроке

// time: O(N)
// mem: O(1), но изза итогового копирования будет O(N)