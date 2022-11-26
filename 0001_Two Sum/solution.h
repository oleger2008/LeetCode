class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // v1
        // for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        //     int to_find = target - *iter;
        //     for (auto jter = nums.begin(); jter != nums.end(); ++jter) {
        //         if (iter == jter) {
        //             continue;
        //         }
        //         if (*jter == to_find) {
        //             result.push_back(static_cast<int>(iter - nums.begin()));
        //             result.push_back(static_cast<int>(jter - nums.begin()));
        //             break;
        //         }
        //     }
        //     if (!result.empty()) {
        //         break;
        //     }
        // }
        std::unordered_map<int, size_t> num_to_index;
        for (size_t i = 0; i < nums.size(); ++i) {
            int to_find = target - nums.at(i);
            if (num_to_index.count(to_find)) {
                result.push_back(i);
                result.push_back(num_to_index.at(to_find));
                break;
            }
            num_to_index[nums[i]] = i;
            
        }
        return result;
    }
};