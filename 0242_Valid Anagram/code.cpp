class Solution {
public:
    bool isAnagram(string s, string t) {
        // return byHashMap(s, t);
        // return bySort(s, t);
        return byArray(s, t);
    }

    bool bySort(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::sort(std::begin(s), std::end(s));
        std::sort(std::begin(t), std::end(t));
        return s == t;
    }

    bool byHashMap(string_view s, string_view t) {
        const size_t size = s.size();
        if (size != t.size()) {
            return false;
        }
        unordered_map<char, size_t> alphabet;
        alphabet.reserve(std::max(s.size(), t.size()));
        for (size_t i = 0u; i < size; ++i) {
            ++alphabet[s[i]];
            --alphabet[t[i]];
        }
        for (const auto [ch, count] : alphabet) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    bool byArray(string_view s, string_view t) {
        std::array<int, 26> char_freqs = {0};
        const size_t size = s.size();
        if (size != t.size()) {
            return false;
        }
        for (size_t i = 0u; i < size; ++i) {
            ++char_freqs[s[i] - 'a'];
            --char_freqs[t[i] - 'a'];
        }
        for (const auto count : char_freqs) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};