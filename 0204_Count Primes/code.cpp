// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Example 2:
// Input: n = 0
// Output: 0

// Example 3:
// Input: n = 1
// Output: 0

// n: [0..5*10^6]

// 10
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,t,t,t,t,t,t,t]
// t - true, isPrime

// start from 2
// its marked as true already
// then mark every num begining from 2^2 = 4 as false
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,t,f]

// 3 - its marked as true already
// then mark every num begining from 3^2 = 9 as false
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 4 - its marked as false, so skip
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 5 - its marked as true already
// then mark every num begining from 5^2 = 25 as false
// but 25 > 10, so skip this op, and skip this check next times
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 6 - its marked as false, so skip
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 7 - its marked as true already, so go next
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 8 - its marked as false, so skip
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 9 - its marked as false, so skip
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// 10 - its marked as false, so skip
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]

// collect all true from array
//  0|1|2|3|4|5|6|7|8|9|10|11
// [f,f,t,t,f,t,f,t,f,f,f]
// ans: 4

// time: O(n)
// mem: O(n)
class Solution {
public:
    int countPrimes(int n) {
        //                    j
        //                i
        //  0|1|2|3|4|5|6|7|8|9|10|11
        // [0,0,1,1,0,1,0,1,0,0,0]
        if (n < 2) return 0;
        std::vector nums(n, 1);
        nums[0] = 0;
        nums[1] = 0;
        bool needCheckSquare = true; // needCheckSquare = fasle
        for (int i = 2; i < nums.size(); ++i) { // i = 7; 3 < 12
            if (!nums[i]) continue; // (nums[7] = 1)
            if (needCheckSquare) { // fasle
                int j = i * i; // 25
                if (j > n) { // 25 > 10
                    needCheckSquare = false;
                    continue;
                }
                for (; j < nums.size(); j += i) { // j = 12; 12 < 11
                    nums[j] = 0;
                }
            }
        }
        return std::accumulate(std::begin(nums), std::end(nums), 0);
    }
};

// time: O(N*logN); mem: O(1)
// class Solution {
// public:
//     int countPrimes(int n) {
//         int result = 0;
//         for (int i = 2; i < n; ++i) {
//             result += isPrime(i);
//         }
//         return result;
//     }
// private:
//     bool isPrime(int n) {
//         // Corner cases
//         if (n <= 1)
//             return false;
//         if (n <= 3)
//             return true;

//         // This is checked so that we can skip
//         // middle five numbers in below loop
//         if (n % 2 == 0 || n % 3 == 0)
//             return false;

//         for (int i = 5; i * i <= n; i = i + 6)
//             if (n % i == 0 || n % (i + 2) == 0)
//                 return false;

//         return true;
//     }

// };