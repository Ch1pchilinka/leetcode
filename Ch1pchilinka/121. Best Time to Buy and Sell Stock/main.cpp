#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int curr_min = prices[0], curr_profit = 0;
    size_t n = prices.size();
    for (size_t i = 1; i < n; ++i) {
      if (prices[i] - curr_min > curr_profit) {
        curr_profit = prices[i] - curr_min;
      }
      if (curr_min > prices[i]) {
        curr_min = prices[i];
      }
    }
    return curr_profit;
  }
};
