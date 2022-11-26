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
        stringstream input(s);
        int result = 0;
        char c = '0';
        while (input.good()) {
            c = input.get();
            if (c == 'I') {
                result += GetI(input);
            } else if (c == 'X') {
                result += GetX(input);
            } else if (c == 'C') {
                result += GetC(input);
            } else if ((c == 'V') || (c == 'L') || (c == 'D') || (c == 'M')) {
                result += romans_.at(c);
            }
        }
        return result;
    }
    
private:
    unordered_map<char, int16_t> romans_;
    
    int GetI(istream& input) {
        const char i = 'I';
        char next = input.get();
        if (input.good()) {
            if ((next == 'V') || (next == 'X')) {
                return romans_.at(next) - romans_.at(i);
            } else {
                input.putback(next);
            }
        }
        return romans_.at(i);
    }
    
    int GetX(istream& input) {
        const char x = 'X';
        char next = input.get();
        if (input.good()) {
            if ((next == 'L') || (next == 'C')) {
                return romans_.at(next) - romans_.at(x);
            } else {
                input.putback(next);
            }
        }
        return romans_.at(x);
    }
    
    int GetC(istream& input) {
        const char c = 'C';
        char next = input.get();
        if (input.good()) {
            if ((next == 'D') || (next == 'M')) {
                return romans_.at(next) - romans_.at(c);
            } else {
                input.putback(next);
            }
        }
        return romans_.at(c);
    }
};