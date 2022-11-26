class Solution {
public:
    int reverse(int x) {
//         v1
        // bool is_negative = false;
        // if (x < 0) {
        //     is_negative = true;
        // }
        // string s = to_string(x);
        // std::reverse(s.begin(), s.end());
        // if (is_negative) {
        //     s.insert(0, 1, '-');
        // }
        // try {
        //     return stoi(s);
        // } catch(...) {
        //     return 0;
        // }
        
//         v2
        if (!x) {
            return 0;
        }
        int64_t result = 0;
        while (x) {
            int rest = x % 10;
           
            result *= 10;
            if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
                return 0;
            }
            result += rest;
            x /= 10;
        }
        return result;
    }
};