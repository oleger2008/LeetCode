// v1 - naive
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

// v2 - prefix sums
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