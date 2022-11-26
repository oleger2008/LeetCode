class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> collection;
        for (const auto n : nums) {
            if (collection.count(n)) {
                return true;
            }
            collection.insert(n);
        }
        return false;
    }
};