// Given a square matrix mat, return the sum of the matrix diagonals.
// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

// Example 1:
// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.

// Example 2:
// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8

// Example 3:
// Input: mat = [[5]]
// Output: 5

// arr count = arr.lenght = n
// n: [1..100]
// val: [1..100]

// we can see that in bordered arrays we need to take bordered elems
// then in bordered - 1, take border - 1 elems and etc

// time: O(n)
// mem: O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //          0| 1| 2| 3| 4
// Input: mat = [0 [1, 2, 3, 4],
//               1 [5, 6, 7, 8],
//               2 [9, 10,11,12],
//               3 [13,14,15,16]]
// size = 4

        int diff = mat.size() / 2 - 1; // diff = 1
        int result = (mat.size() % 2) // result = 34
            ? result = mat[diff + 1][diff + 1]
            : 0;

        int top = 0; // top = 0
        int left = 0; // left = 0
        int right = mat.size() - 1; // right = 3
        int bot = right; // bot = 2
        while (diff >= 0) { // 1 >= 0
        //                  0 + 1        0 + 1
            result += mat[top + diff][left + diff]; // 0 + 11
            //              0 + 1         3 - 1
            result += mat[top + diff][right - diff]; // 11 + 10
            //              3 - 1       0 + 1
            result += mat[bot - diff][left + diff]; // 21 + 7
            //              3 - 1        3 - 1
            result += mat[bot - diff][right - diff]; // 28 + 6
            --diff; // 2 - 1 = 1
        }
        return result;
    }
};