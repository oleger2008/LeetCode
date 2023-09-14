// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

// Example 1:
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

// Example 2:
// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

// Example 3:
// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

// [[10,16],[2,8],[1,6],[7,12]]
// 
//  1                6
//  |----------------|
// 
//      2                     8
//      |---------------------|
//                        7                 12
//                        |-----------------|
//                                    10                    16
//                                     |--------------------|

// 1. sort array by intervals begin
// 2. make new arr intervals with overlaps
// 3. optimisation for step 2: save only last overlap
// 4. if no overlap in next interval, then save this interval instead of last overlap
// 5. while all this arr scan, save result and increment it when step 4 happens

// arr.size: [1..10^5]
// interval.val: [-2^31..2^31 - 1]
// interval.size: [2]

// time: O(N*logN)
// mem: O(1)
class Solution {
    using Interval = vector<int>;
public:
    int findMinArrowShots(vector<Interval>& points) {
        sortIntervals(points);
        Interval lastOverlap{points.front()};
        int result = 1;
        for (const auto& item : points) {
            if (item.front() > lastOverlap.back()) {
                ++result;
                lastOverlap = item;
                continue;
            }
            lastOverlap.front() = std::max(lastOverlap.front(), item.front());
            lastOverlap.back() = std::min(lastOverlap.back(), item.back());
        }
        return result;
    }

private:
    void sortIntervals(vector<Interval>& points) {
        std::sort(std::begin(points), std::end(points),
                [](const auto& lhs, const auto& rhs) {
                    return lhs.front() < rhs.front();
                });
    }
};