class Solution {
public:
    // O(N * logN)
//     vector<int> countBits(int n) {
//         vector<int> result;
//         result.reserve(n + 1);
        
//         for (int i = 0; i <= n; ++i) {
//             int sum = 0;
//             int num = i;
//             while (num != 0) {
//                 sum += num % 2;
//                 num /= 2;
//             }
//             result.push_back(sum);
//         }
//         return result;
//     }
    
    // O(N)
    vector<int> countBits(int n) {
        vector<int> result;
        result.reserve(n + 1);
        result.push_back(0);
        
        for (int i = 1; i <= n; ++i) {
            result.push_back(result[i / 2] + (i % 2));
        }
        return result;
    }
};