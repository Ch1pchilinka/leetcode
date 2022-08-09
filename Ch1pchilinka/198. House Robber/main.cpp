#include <iostream>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    size_t n = nums.size();
    std::vector<std::pair<int, int>> vec(n);
    vec[0].first = 0;
    vec[0].second = nums[0];
    for (size_t i = 1; i < n; ++i) {
      vec[i].first = std::max(vec[i - 1].first, vec[i - 1].second);
      vec[i].second = nums[i] + vec[i - 1].first;
    }
    return std::max(vec[n - 1].first, vec[n - 1].second);
  }
};