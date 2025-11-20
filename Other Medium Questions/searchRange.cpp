#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2, -1);
            int left = 0, right = nums.size() - 1;
            // Find the first occurrence of target
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            // If we found the target, we need to find the last occurrence
            if (left < nums.size() && nums[left] == target) {
                result[0] = left;
            }


            left = 0;
            right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (right >= 0 && nums[right] == target) {
                result[1] = right;
            }
            return result;
        }
};