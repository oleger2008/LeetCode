// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21

// x: [-2*10^31..2*10^31 - 1]

// in: 123
// result = 0

// in: 123 -> 12
// result = 3

// in: 12 -> 1
// result = 3 * 10 + 2

// in: 1 -> 0
// result = (3 * 10 + 2) * 10 + 1

// time: O(1)
// mem: O(1)
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        constexpr int max = std::numeric_limits<int>::max() / 10;
        constexpr int min = std::numeric_limits<int>::min() / 10;
        while (x) {
            if (min > result || result > max) return false;
            result = (result * 10) + (x % 10);
            x /= 10;
        }
        return result;
    }
};