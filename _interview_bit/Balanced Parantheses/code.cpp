// Given a string A consisting only of '(' and ')'.

// You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.

// Input Format
// First argument is an string A.
// Output Format
// Return 1 if parantheses in string are balanced else return 0.

// Input 1:
// A = "(()())"
// Output 1:
// 1
// Explanation 1:
// Given string is balanced so we return 1

// Input 2:
// A = "(()"
// Output 2:
// 0
// Explanation 2:
// Given string is not balanced so we return 0

// str.size: [1..10^5]
// char: only '()'

// idea: use counter
// do +1 when it's open bracet
// do -1 when it's close bracet
// is counter < 0 -> false
// if counter != 0 after scan -> false

// time: O(n)
// mem: O(1)
int Solution::solve(string A) {
    int counter = 0;
    for (const auto c : A) {
        if (c == '(')
            ++counter;
        if (c == ')')
            --counter;
        if (counter < 0) return false;
    }
    if (counter != 0) return false;
    return true;
}
