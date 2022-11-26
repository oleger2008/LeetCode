class Solution {
public:
    int searchInsert(const vector<int>& nums, const int target) {
        //v1 Easy way
        // return static_cast<int>(distance(nums.begin(), 
        //         lower_bound(nums.begin(), nums.end(), target)));
        
        //v2 My way
        return static_cast<int>(distance(nums.cbegin(),
                lowerBound(nums.cbegin(), nums.cend(), target)));
    }
    
private:
    using ConstIt = vector<int>::const_iterator;
    
    ConstIt lowerBound(const ConstIt first, const ConstIt last,
                       const int target) const {
        const size_t count = last - first;
        if (count == 0u) {
            return last;
        }
        if (count == 1u) {
            if (*first < target) {
                return last;
            }
            return first;
        }
        const ConstIt mid = first + count / 2;
        if (*mid == target) {
            return mid;
        }
        if (*mid < target) {
            return lowerBound(mid, last, target);
        }
        return lowerBound(first, mid, target);
    }
};