// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

// Example 2:
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

// n: [0..10^5]


// 0 --> 0     | 0
// 1 --> 1     | 1 | use prev + 1
// 2 --> 10    | 1 |  1, 2 - is prev(0, 1) + 1
// 3 --> 11    | 2 |
// 4 --> 100   | 1 |  1, 2, 2, 3 - is prev(0,1,1,2) + 1
// 5 --> 101   | 2 |
// 6 --> 110   | 2 |
// 7 --> 111   | 3 |


// time: O(n)
// mem: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result; result.reserve(n + 1);
        result.push_back(0);
        int help = 1;
        for (int i = 1; i <= n; ++i) {
            result.push_back(result[i - help] + 1);
            if ((i + 1) % help == 0) {
                help = help << 1;
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     // O(N * logN)
// //     vector<int> countBits(int n) {
// //         vector<int> result;
// //         result.reserve(n + 1);

// //         for (int i = 0; i <= n; ++i) {
// //             int sum = 0;
// //             int num = i;
// //             while (num != 0) {
// //                 sum += num % 2;
// //                 num /= 2;
// //             }
// //             result.push_back(sum);
// //         }
// //         return result;
// //     }

//     // O(N)
//     vector<int> countBits(int n) {
//         vector<int> result;
//         result.reserve(n + 1);
//         result.push_back(0);

//         for (int i = 1; i <= n; ++i) {
//             result.push_back(result[i / 2] + (i % 2));
//         }
//         return result;
//     }
// };