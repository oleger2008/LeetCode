class Solution {
public:
    // my naive
    // int maxArea(vector<int>& height) {
    //     int result = 0;
    //     const auto size = height.size();
    //     for (size_t i = 0u; i < size; ++i) {
    //         const int left = height[i];
    //         for (size_t j = i; j < size; ++j) {
    //             const int right = height[j];
    //             const int minHeight = std::min(left, right);
    //             result = std::max(result, minHeight * static_cast<int>(j - i));
    //         }
    //     }
    //     return result;
    // }

    int maxArea(vector<int>& height) {
        int result = 0;
        auto left = height.begin();
        auto right = prev(height.end());
        while (left != right) {
            const auto maxHeight = std::min(*left, *right);
            result = std::max(result, static_cast<int>(right - left) * maxHeight);
            while ((left != right) && (*left <= maxHeight)) {
                ++left;
            }
            while ((left != right) && (*right <= maxHeight)) {
                --right;
            }
        }
        return result;
    }
};