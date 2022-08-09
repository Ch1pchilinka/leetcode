#include <iostream>
#include <vector>

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    std::vector<long> dyn(n);
    dyn[0] = 1;
    dyn[1] = 2;
    for (int i = 2; i < n; ++i) {
      dyn[i] = dyn[i - 1] + dyn[i - 2];
    }
    return dyn[n - 1];
  }
};
