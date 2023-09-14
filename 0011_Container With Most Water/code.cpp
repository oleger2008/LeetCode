// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// it's literaly to pointers:
// to have biggest area we should take max wide, so we can start
// check other vertical side: begin or end
// tip: fixing one side won't make any sense because arae would
// defined by it, opposite higher side won't make any impact
// We should move ptr that points on smallest height to have chance
// take bigger one

// arr.size: [2..10^5]
// val: [0..10^4]

// time: O(n)
// mem: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int lenght = right - left;
            int cur = lenght * std::min(height[left], height[right]);
            result = std::max(result, cur);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};