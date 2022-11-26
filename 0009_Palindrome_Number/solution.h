class Solution {
public:
    bool isPalindrome(int x) {
        // v1
        // runtime = 8 ms; memory = 5.7 MB
//         if (x < 0) {
//             return false;
//         }
//         auto x_copy = x;
//         int64_t result = 0;
//         while (x_copy) {
//             int rest = x_copy % 10;
           
//             result *= 10;
//             if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
//                 return false;
//             }
//             result += rest;
//             x_copy /= 10;
//         }
//         return x == result;
        
        // v2 - origin solution
        // runtime = 16 ms; memory = 5.7 MB
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber/10;
    }
};