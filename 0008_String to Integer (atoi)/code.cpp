class Solution {
public:
    int myAtoi(string s) {
        const int size = s.size();
        int i = 0;

        //remove leading whitespaces
        for (; i < size && s[i] == ' '; ++i) {}
        if (i >= size) return 0;

        // check sign before number
        bool isNegative = false;
        if (s[i] == '-') {
            isNegative = true;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }

        int result = 0;
        // traverse until isDigit
        for (; i < size && isDigit(s[i]); ++i) {
            int cur = s[i] - '0';
            if (result > std::numeric_limits<int>::max() / 10 ||
                (result == std::numeric_limits<int>::max() / 10 && cur > 7)) {
                return isNegative
                        ? std::numeric_limits<int>::min()
                        : std::numeric_limits<int>::max();
            }
            result *= 10;
            result += cur;
        }
        return isNegative ? -result : result;
    }

private:
    bool isDigit(const char c) {
        return c >= '0' && c <= '9';
    }
};