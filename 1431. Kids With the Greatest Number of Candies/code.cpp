class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto m = std::max_element(std::begin(candies), std::end(candies));
        std::vector<bool> result(std::size(candies), false);
        for (int i = 0; i < std::size(candies); ++i) {
            result[i] = (candies[i] + extraCandies >= *m);
        }
        return result;
    }
};