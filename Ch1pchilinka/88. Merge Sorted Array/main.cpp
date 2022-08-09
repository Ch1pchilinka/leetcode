#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int ptr1 = m - 1, ptr2 = n - 1, ptr3 = n + m - 1;
    while (ptr2 >= 0) {
      if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) {
        nums1[ptr3--] = nums1[ptr1--];
      } else {
        nums1[ptr3--] = nums2[ptr2--];
      }
    }
  }
};