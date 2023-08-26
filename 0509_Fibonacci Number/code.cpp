// Example 1:
// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

// Example 2:
// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

// Example 3:
// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// n: [0..30]
// warmup: [0, 1, 1, 2, 3, 5, 8, 13]
//          0  1  2  3  4  5  6  7

// warmup:
// time: O(n)
// memory: O(n)

// request:
// time: O(1)
// memory: O(1)

// class Solution {
// public:
//     Solution() {
//         warmup();
//     }

//     int fib(int n) {
//         return nums_[n];
//     }

// private:
//     void warmup() {
//         const size_t size = 31u;
//         nums_.reserve(size);
//         nums_.push_back(0);
//         nums_.push_back(1);
//         for (size_t i = 2u; i < size; ++i) {
//             nums_.push_back(nums_[i - 1] + nums_[i - 2]);
//         }
//     }

//     vector<uint64_t> nums_;
// };


// without warmup
// with two vars
// [0, 1, 1, 2, 3, 5, 8, 13]
//  0  1  2  3  4  5  6  7

// time: O(n)
// memory: O(1)

class Solution {
public:
    int fib(int n) {
        int first = 0;
        int second = 1;
        if (n == 0) return first;
        if (n == 1) return second;

        int cur = 0;
        for (int i = 2; i <= n; ++i) {
            cur = first + second;
            first = second;
            second = cur;
        }
        return cur;
    }
};