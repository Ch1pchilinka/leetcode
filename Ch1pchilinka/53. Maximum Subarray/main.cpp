#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int curr_min = std::min(0, nums[0]), curr_max_sum = nums[0];
    size_t n = nums.size();
    for (size_t i = 1; i < n; ++i) {
      nums[i] += nums[i - 1];
      if (nums[i] - curr_min > curr_max_sum) {
        curr_max_sum = nums[i] - curr_min;
      }
      if (curr_min > nums[i]) {
        curr_min = nums[i];
      }
    }
    return curr_max_sum;
  }
};