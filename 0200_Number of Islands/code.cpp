// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// 1 <= m, n <= 300
// m = grid.size
// n = grid.front().size
// value: [0, 1]

// whatched idea:
// traverse over matrix
// if catch '1' then mark it as '0' and traverse
// over the adjacent vertexes to mark them '0' too

// time: O(m * n)
// mem: O(log(m * n))
class Solution {
    using Grid = vector<vector<char>>;
public:
    int numIslands(Grid& grid) {
        const int lenght = grid.size();
        const int width = grid.front().size();
        int result = 0;
        for (int i = 0; i < lenght; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    eraseIsland(grid, i, j);
                }
            }
        }
        return result;
    }

private:
    void eraseIsland(Grid& grid, int i, int j) {
        const int lenght = grid.size();
        const int width = grid.front().size();
        if (i < 0 || j < 0 || i >= lenght || j >= width || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        eraseIsland(grid, i - 1, j);
        eraseIsland(grid, i + 1, j);
        eraseIsland(grid, i, j - 1);
        eraseIsland(grid, i, j + 1);
    }
};