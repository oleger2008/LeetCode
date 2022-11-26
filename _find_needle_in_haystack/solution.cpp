class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        size_t haystack_size = haystack.size();
        size_t needle_size = needle.size();
        if (haystack_size < needle_size) {
            return -1;
        }
        
        FillSymbols(needle);
        
        for (size_t i = 0; i < needle_size; ++i) {
            if (char c = haystack.at(i); symbols_.count(c)) {
                --symbols_.at(c);
            }
        }
        
        if (IsSymbolsEmpty()) {
            return 0;
        }
        if (haystack_size == needle_size) {
            return -1;
        }
        
        for (size_t i = 0, size = haystack_size - needle_size; i < size; ++i) {
            if (char c = haystack.at(i); symbols_.count(c)) {
                ++symbols_.at(c);
            }
            if (char c = haystack.at(i + needle_size); symbols_.count(c)) {
                --symbols_.at(c);
            }
            if (IsSymbolsEmpty()) {
                return (i + 1);
            }
        }
        
        return -1;
    }
    
private:
    unordered_map<char, int> symbols_;
    
    void FillSymbols(const string& str) {
        for (const char c : str) {
            ++symbols_[c];
        }
    }
    
    bool IsSymbolsEmpty() const {
        for (const auto [_, count] : symbols_) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
};