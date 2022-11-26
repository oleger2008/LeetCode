class Solution {
public:
    Solution()
    : romans_({
        {'I', 1}, 
        {'V', 5}, 
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        })
    {}
    
    int romanToInt(string s) {
        int result = romans_.at(s.back());
        size_t size = s.size();
        for (size_t i = 0; (i + 1u) < size; ++i) {
            if (romans_.at(s.at(i)) < romans_.at(s.at(i + 1u))) {
                result -= romans_.at(s.at(i));
            } else {
                result += romans_.at(s.at(i));
            }
        }
        return result;
    }
    
private:
    unordered_map<char, int16_t> romans_;
};