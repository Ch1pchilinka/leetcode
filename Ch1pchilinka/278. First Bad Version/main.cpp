#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
      long left = 1, right = n, mid;
      while (left < right) {
        mid = (left + right) / 2;
        if (isBadVersion(mid)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
  }
};