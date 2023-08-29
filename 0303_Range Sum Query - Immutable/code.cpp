// Given an integer array nums, handle multiple queries of the following type:
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:
// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]
// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

// arr.size: [1..10^4]
// value: [-10^5..10^5]
// 0 <= left <= right < nums.length

//    [-2,  0, 3, -5,  2, -1]
// [0, -2, -2, 1, -4, -2, -3]
// sum(l, r) = px[r + 1] - px[l]

// v1 - naive; ctr: time: O(n); mem: O(n); sumRange: time: O(n)
class NumArray {
public:
    NumArray(vector<int>& nums)
    : nums_(move(nums)) 
    {}
    
    int sumRange(int left, int right) {
        return accumulate(begin(nums_) + left, begin(nums_) + right + 1, 0);
    }
    
private:
    vector<int> nums_;
};

// v2 - prefix sums; ctr: time: O(n); mem: O(n); sumRange: time: O(1)
class NumArray_p {
public:
    NumArray(vector<int>& nums)
    : nums_() {
        nums_.reserve(nums.size() + 1u);
        nums_.push_back(0);
        size_t i = 0;
        for (const auto num : nums) {
            nums_.push_back(nums_[i] + num);
            ++i;
        }
    }
    
    int sumRange(int left, int right) {
        return nums_[right + 1] - nums_[left];
    }
    
private:
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */