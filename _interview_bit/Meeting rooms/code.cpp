// Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
// Where:
// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
 

// Find the minimum number of conference rooms required so that all meetings can be done.
// Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

// arr.size: [1..10^5]
// interval.val: [0..2*10^9]

// Input 1:
//  A = [      [0, 30]
//             [5, 10]
//             [15, 20]
//      ]
// Output 1: 2

// Input 2:
//  A =  [     [1, 18]
//             [18, 23]
//             [15, 29]
//             [4, 15]
//             [2, 11]
//             [5, 13]
//       ]
// Output 2: 4

// 1. sort array by interval begin
// 1. make array with points [point, plus/minus room]
// 2. scan array and do: +1 when start interval; -1 when end interval
// 3. also while scaning watch the maximum of rooms
 
// 1                                             18
// |---------------------------------------------|
//                                               18                 23
//                                               |------------------|
//                                         15                                        29
//                                         |-----------------------------------------|
//                 4                       15
//                 |-----------------------|
//        2                        11
//        |------------------------|
//                         5           13
//                         |-----------|


// time: O(N*logN)
// mem: O(N)
int Solution::solve(vector<vector<int> > &A) {
    std::vector<pair<int, int>> points;
    for (const auto& item : A) {
        points.emplace_back(item.front(), 1);
        points.emplace_back(item.back(), -1);
    }
    std::sort(std::begin(points), std::end(points),
            [](const auto lhs, const auto rhs) {
                if (lhs.first == rhs.first) {
                    return lhs.second < rhs.second;
                }
                return lhs.first < rhs.first;
            });
    int result = 0;
    int cur = 0;
    for (const auto [_, inc] : points) {
        cur += inc;
        result = std::max(result, cur);
    }
    return result;
}
