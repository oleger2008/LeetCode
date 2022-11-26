class Solution {
public:
    Solution() = default;
    
    bool isValid(string s) {
        for (const char c : s) {
            switch (c) {
                case '(':
                    [[fallthrough]];
                case '{':
                    [[fallthrough]];
                case '[':
                    stck_.push(c);
                    continue;
                    
                case ')':
                    if (!stck_.empty() && stck_.top() == '(') {
                        stck_.pop();
                        continue;
                    } else {
                        return false;
                    }
                case '}':
                    if (!stck_.empty() && stck_.top() == '{') {
                        stck_.pop();
                        continue;
                    } else {
                        return false;
                    }
                case ']':
                    if (!stck_.empty() && stck_.top() == '[') {
                        stck_.pop();
                        continue;
                    } else {
                        return false;
                    }
            }
        }
        return stck_.empty();
    }
    
private:
    stack<char> stck_;
};