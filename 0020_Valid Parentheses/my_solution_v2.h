class Solution {
public:
    Solution()
    : stck_()
    , bracets_({
        {')', '('}, 
        {'}', '{'},
        {']', '['}
        }) {}
    
    bool isValid(string s) {
        for (const char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stck_.push(c);
            } else if (!stck_.empty() && bracets_.count(c) && bracets_.at(c) == stck_.top()) {
                stck_.pop();
            } else {
                return false;
            }
        }
        return stck_.empty();
    }
    
private:
    stack<char> stck_;
    unordered_map<char, char> bracets_;
};