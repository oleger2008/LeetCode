class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto begin = nums.begin();
        auto mid = begin + (nums.size() / 2);
        auto end = nums.end();
        
        while (target != *mid) {
            if (target < *mid) {
                // begin is same
                end = mid;
            } else if (target > *mid) {
                begin = mid + 1;
                // end is same
            }
            if (begin == end) {
                return -1;
            }
            mid = begin + distance(begin, end) / 2;
        }
        return distance(nums.begin(), mid);
    }
};