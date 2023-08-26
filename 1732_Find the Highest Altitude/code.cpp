// Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

// Input: gain = [-4,-3,-2,-1,4,3,2]
// Output: 0
// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

// [1]
// [0, 1]
// ans: 1

// [-1]
// [0, -1]
// ans: 0

// max: 0
// 0 [-5,1,5,0,-7]
// [-5, -4]
// cur + prev

// array size: [1..100]
// value: [-100, 100]

// time: O(N)
// memory: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int prev = 0;
        for (int i = 0; i < gain.size(); ++i) {  
            prev = gain[i] + prev;
            result = std::max(result, prev);
        }
        return result;
    }
};