// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// arr.size: [1..10^4]
// interval.length: [2]
// interval val: [0..10^4]

// explanation:
//   A(start)                B(end)
//   |-----------------------|
//              C(start)                D(end)
//              |-----------------------|
// can see: A < C -> so arr of intervals should be sorted
// A < C < B -> so CD started being in AB - overlap
// after merge it becomes: AD

// 1. sort intervals by begin
// 2. scan array and add to result only not overlapping ones

//   1        3
//   |--------|
//        2           6
//        |-----------|
//                  4     7
//                  |-----|
//                           8     10
//                           |-----|
//                                             15        18 
//                                             |---------|
// 1. result: [[1,3]]
// 2. [[1,6]]
// 3. [[1,7]]
// 4. [[1,7], [8,10]]
// 5. [[1,7], [8,10], [15,18]]

// time: O(N*logN)
// mem: O(N)
class Solution {
    using Interval = vector<int>;
public:
    //  [[1,4],[4,5]]
    vector<Interval> merge(vector<Interval>& intervals) {
        sortIntervals(intervals);
        vector<Interval> result;
        result.reserve(intervals.size());
        result.push_back(intervals.front());
        for (const auto& item : intervals) {
            auto& last_inter = result.back();
            if (item.front() > last_inter.back()) {
                result.push_back(item);
                continue;
            }
            if (item.back() > last_inter.back()) {
                last_inter.back() = item.back();
            }
        }
        return result;
    }

private:
    void sortIntervals(vector<Interval>& intervals) {
        std::sort(std::begin(intervals), std::end(intervals), 
            [](const auto& lhs, const auto& rhs) {
                return lhs.front() < rhs.front();
            });
    }
};