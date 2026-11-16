#pragma once

#include "0011_100_SameTree.h"
#include <vector>

/*
* Given an integer array nums where the elements are sorted in ascending
* order, convert it to a height-balanced binary search tree.
* 
* Example 1:
* Input: nums = [-10,-3,0,5,9]
* Output: [0,-3,9,-10,null,5]
* Explanation: [0,-10,5,null,-3,null,9] is also accepted:
* 
* Example 2:
* Input: nums = [1,3]
* Output: [3,1]
* Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
* 
* Constraints:
* + 1 <= nums.length <= 10^4
* + -10^4 <= nums[i] <= 10^4
* + nums is sorted in a strictly increasing order.
*/
namespace ConvertSortedArrayToBinarySearchTree {
    using SameTree::TreeNode;

    class Solution {
    public:

        TreeNode* buildTree(int left, int right, std::vector<int> nums) {

            if (left > right) {
                return nullptr;
            }

            int mid = (left + right) / 2;
            int value = nums[mid];
            TreeNode* root = new TreeNode(value);


            root->left = buildTree(left, mid - 1, nums);
            root->right = buildTree(mid + 1, right, nums);

            return root;
        }

        TreeNode* sortedArrayToBST(std::vector<int>& nums) {
            if (nums.size() == 0) return nullptr;
            if (nums.size() == 1) {
                return new TreeNode(nums[0]);
            }

            int left = 0;
            int right = nums.size() - 1;
            TreeNode* root = buildTree(left, right, nums);

            return root;

        }
    };
}