class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t haystack_size = haystack.size();
        size_t needle_size = needle.size();
        if (needle.empty()) {
            return 0;
        }
        if (haystack_size < needle_size) {
            return -1;
        }
        
        for (size_t i = 0, size = haystack_size - needle_size; i <= size; ++i) {
            if (needle == haystack.substr(i, needle_size)) {
                return i;
            }
        }
        return -1;
    }
};