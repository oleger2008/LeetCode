class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result(word1.size() + word2.size(), '\0');
        const size_t size = std::min(word1.size(), word2.size());
        size_t i = 0, j = 0;
        while (j < size) {
            result[i++] = word1[j];
            result[i++] = word2[j++];
        }
        while (j < word1.size()) {
            result[i++] = word1[j++];
        }
        while (j < word2.size()) {
            result[i++] = word2[j++];
        }
        return result;
    }
};