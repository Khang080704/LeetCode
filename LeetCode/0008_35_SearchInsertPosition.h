#pragma once

#include<vector>
#include<iostream>

/*
* Given a sorted array of distinct integers and a target value, return
* the index if the target is found. If not, return the index where it
* would be if it were inserted in order.
* 
* You must write an algorithm with O(log n) runtime complexity.
* 
* Example 1:
* Input: nums = [1,3,5,6], target = 5
* Output: 2
* 
* Example 2:
* Input: nums = [1,3,5,6], target = 2
* Output: 1
* 
* Example 3:
* Input: nums = [1,3,5,6], target = 7
* Output: 4
*/
namespace SearchInsertPosition {
    class Solution {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int mid = (left + right) / 2;

            while (left <= right) {
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
                mid = (left + right) / 2;
            }

            

            if (nums[mid] < target) {
                
                return mid + 1;
            }
            else {
                if (mid == 0) {
                    return 0;
                }
                return mid - 1;
            }
        }

    };

    void testInsertPostion() {
        std::vector<int> a{ 1, 3, 5, 6 };
        Solution s;
        std::cout << s.searchInsert(a, 2);
    }
}
