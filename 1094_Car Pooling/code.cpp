// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// Example 1:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Example 2:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

// [[2,1,5],[3,3,7]]
// 1, +2                  5, -2
// |----------------------|
//           3, +3                       7, -3
//           |---------------------------|

// 1. make array of pairs: [point, plus/minus psg count]
// 2. sort it, if equal point, then first should be minus
// 3. scan array and refresh max psg count in a moment. if more than capacity than return false

// arr.size: [1..1000]
// trip.size = 3
// psg count: [1..100]
// from, to: [0..1000]
// capacity: [1..10^5]


// time: O(N*LogN)
// mem: O(N)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const auto points = makePoints(trips);
        int cur = 0;
        for (const auto [_, count] : points) {
            cur += count;
            if (cur > capacity) return false;
        }
        return true;
    }

private:
    vector<pair<int, int>> makePoints(const vector<vector<int>>& trips) {
        vector<pair<int, int>> points;
        for (const auto &trip : trips) {
            auto count = trip[0];
            auto from = trip[1];
            auto to = trip[2];
            points.emplace_back(from, count);
            points.emplace_back(to, -count);
        }
        std::sort(std::begin(points), std::end(points),
                [](const auto lhs, const auto rhs) {
                    if (lhs.first == rhs.first) {
                        return lhs.second < rhs.second;
                    }
                    return lhs.first < rhs.first;
                });
        return points;
    }
};