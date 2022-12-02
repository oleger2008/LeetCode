class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto begin = letters.begin();
        auto end = letters.end();
        auto mid = letters.begin() + letters.size() / 2;
        
        char result = *begin;
        while (begin != end) {
            if (*mid > target) {
                end = mid;
                result = *mid;
            } else {
                begin = mid + 1;
            }
            mid = begin + distance(begin, end) / 2;
        }
        return result;
    }
};