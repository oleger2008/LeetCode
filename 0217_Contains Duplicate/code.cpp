// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// dict: [1, 2, 3]
// arr [1,2,3,1]
// anw: true

// arr.size: [1..10^5]
// value: [-10^9..10^9]

// time: O(n)
// memory: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> collection;
        collection.reserve(nums.size());
        for (const auto n : nums) {
            if (collection.count(n)) {
                return true;
            }
            collection.insert(n);
        }
        return false;
    }
};