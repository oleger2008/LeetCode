class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(std::size(numbers)) - 1;
        while (left != right) {
            int rest = target - numbers[left];
            if (rest == numbers[right]) {
                return {left + 1, right + 1};
            }
            if (rest > numbers[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};