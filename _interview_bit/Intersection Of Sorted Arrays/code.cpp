// Find the intersection of two sorted arrays OR in other words,
// given 2 sorted arrays, find all the elements which occur in both arrays.
// NOTE: For the purpose of this problem ( as also conveyed by the sample case ),
// assume that elements that appear more than once in both arrays should be included
// multiple times in the final output.

// Input 1:
// A: [1 2 3 3 4 5 6]
// B: [3 3 5]
// Output 1: [3 3 5]

// Input 2:
// A: [1 2 3 3 4 5 6]
// B: [3 5]
// Output 2: [3 5]

// arr.size: [1..10^6] (for both arrays)
// val: ?

// use two pointers, one on each array
//  l
// [1 2 3 3 4 5 6]
//  r
// [3 3 5]
// move one if it points on value that is less, than value pointed by other
// a[l] < b[r]

//    l
// [1 2 3 3 4 5 6]
//  r
// [3 3 5]
// a[l] < b[r]

//      l
// [1 2 3 3 4 5 6]
//  r
// [3 3 5]
// a[l] == b[r]
// collect in result [3], move both

//        l
// [1 2 3 3 4 5 6]
//    r
// [3 3 5]
// a[l] == b[r]
// result [3, 3]

//          l
// [1 2 3 3 4 5 6]
//      r
// [3 3 5]
// a[l] < b[r]
// result [3, 3]

//            l
// [1 2 3 3 4 5 6]
//      r
// [3 3 5]
// a[l] == b[r]
// result [3, 3, 5]

//              l
// [1 2 3 3 4 5 6]
//         r
// [3 3 5]
// end, cause r is out of bound
// result [3, 3, 5]

// time: O(min(a.size, b.size))
// mem: O(min(a.size, b.size))
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int left = 0;
    int right = 0;
    vector<int> result;
    result.reserve(std::min(A.size(), B.size()));
    while ((left < A.size()) && (right < B.size())) {
        if (A[left] < B[right]) {
            ++left;
            continue;
        } 
        if (A[left] > B[right]) {
            ++right;
            continue;
        }
        result.push_back(A[left]);
        ++left;
        ++right;
    }
    return result;
}
