#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

class Solution {
    public:
        int threeSumClosest(std::vector<int>& nums, int target) {
            std::sort(nums.begin(), nums.end());
            int closestSum = nums[0] + nums[1] + nums[2];
            for (size_t i = 0; i < nums.size() - 2; ++i) {
                size_t left = i + 1;
                size_t right = nums.size() - 1;
                while (left < right) {
                    int currentSum = nums[i] + nums[left] + nums[right];
                    if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                        closestSum = currentSum;
                    }
                    if (currentSum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
            return closestSum;
        }
};