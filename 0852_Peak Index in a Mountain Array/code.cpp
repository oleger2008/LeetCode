// An array arr is a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// arr.size: [3...10^5]
// val: [0...10^6]
// guaranty on having edge

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// 1. choose comp to divide on two pieces: true or false
// 2. choose whether left or right would contain answer, whether out of bound

// comp: arr[i] < arr[i + 1] | answer in right
// [0,10,5,2]
// |0|1 |2|3|4
// |t|f |f|f|
//l
//         r
//    m
// arr[m] < arr[m + 1] = false, so r = m

// [0,10,5,2]
// |0|1 |2|3|4
// |t|f |f|f|
//l
//    r
//  m
// arr[m] < arr[m + 1] = true, so l = m

// [0,10,5,2]
// |0|1 |2|3|4
// |t|f |f|f|
//  l
//    r
// r -  l == 1 <- cond to stop
// ans in r

// time: O(logN)
// mem: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = -1;
        int right = arr.size() - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (comp(arr[mid], arr[mid + 1])) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
private:
    bool comp(int cur, int next) {
        return cur < next;
    }
};