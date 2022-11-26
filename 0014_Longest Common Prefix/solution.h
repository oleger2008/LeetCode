class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        string result = *strs.begin();
        for (auto iter = next(strs.begin()); iter != strs.end(); ++iter) {
            if (iter->size() < result.size()) {
                result.resize(iter->size());
            }
            const size_t size = result.size();
            for (size_t i = 0; i < size; ++i) {
                if (result.at(i) != iter->at(i)) {
                    result = result.substr(0u, i);
                    break;
                }
            }
            if (result.empty()) {
                break;
            }
        }
        return result;
    } 
};