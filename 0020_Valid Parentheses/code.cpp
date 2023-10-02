// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false


// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

// arr.size: [1..10^4]
// char: only '()[]{}'

// idea: use stack to collect open bracets
// on close bracet check top of stack on kind of bracet
// if no corresponds - so return false
// if stack empty but current is close bracet - false
// if stack non-empty in the and of scan - false

// stack: '('
// ['(','[','{','}',']',')']
//   i
// cur = '('

// stack: '(', '['
// ['(','[','{','}',']',')']
//       i
// cur = '['

// stack: '(', '[', '{'
// ['(','[','{','}',']',')']
//           i
// cur = '{'

// stack: '(', '[', '{'
// ['(','[','{','}',']',')']
//               i
// cur = '}' ~ '{' from top

// stack: '(', '['
// ['(','[','{','}',']',')']
//                   i
// cur = ']' ~ '[' from top

// stack: '('
// ['(','[','{','}',']',')']
//                       i
// cur = ')' ~ '(' from top

// stack:
// ['(','[','{','}',']',')']
//                           i
// stack empty -> result if true

// time: O(n)
// mem: O(n)
class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracets{{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stck;
        for (const char c : s) {
            if (!bracets.contains(c)) {
                stck.push(c);
                continue;
            }

            if (stck.empty()) return false;
            if (bracets[c] != stck.top()) return false;
            stck.pop();
        }
        if (!stck.empty()) return false;
        return true;
    }
};