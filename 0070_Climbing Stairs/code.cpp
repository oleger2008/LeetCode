// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?


// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 
// n: [1..45]

// it's like fibonacci
// time: O(n)
// mem: O(1)

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        if (n == 1) return first;
        if (n == 2) return second;

        int result = 0;
        while (n > 2) {
            result = first + second;
            first = second;
            second = result;
            --n;
        }
        return result;
    }

    int climbStairsOld(int n) {
        vector<int> dp;
        dp.reserve(n);
        dp.push_back(1);
        dp.push_back(2);
        
        for (size_t i = 2; i < n; ++i) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        
        return dp[n - 1];
    }
};
