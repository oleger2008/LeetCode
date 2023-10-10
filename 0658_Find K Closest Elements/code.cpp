// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:
// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

// 1 case:
// ---|-------------X--------------|-----
//   arr[i]                      arr[i + k]
// can stop

// 2 case:
// ---|----------------------------|-----X---------
//   arr[i]                      arr[i + k]
// should go right

// 3 case:
// -X-|----------------------------|-----
//   arr[i]                      arr[i + k]
// should go to left

// comp is: x - arr[i] <= arr[i + k] - x | means is good to move right
// ans in right
// left = -1; right = arr.size() - k

// k = 4, x = 3
//  m
//    r
//l
// [1,2,3,4,5]
// |3 - 1 <= 4 - 3 = false|3 - 2 <= 5 - 3 = true|

//   r
//  l
// [1,2,3,4,5]

// time: O(logN)
// mem: O(1)
class Solution { // does not pass tests, but solution is right
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) { // k = 3; x =  6+
        //    m
        //      r
        //    l
        // |0|1|2|3|4|5
        // [1,2,3,4,5]
        int left = -1; // 1
        int right = arr.size() - k; // 2
        while (right - left > 1) { // 2 - (1) = 1 > 1
            int mid = left + (right - left) / 2; // 1
            if (comp(arr[mid], x, arr[mid + k - 1])) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return {arr.begin() + right, arr.begin() + right + k};
    }

private:
    bool comp(int left, int mid, int right) { // 2, 6, 4
        return mid - left <= right - mid; // 6 - 2 <= 4 - 6 | false
    }
};