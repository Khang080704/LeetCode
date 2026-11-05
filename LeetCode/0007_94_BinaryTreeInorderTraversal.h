#pragma once

#include<vector>

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]
*/
namespace BinaryTreeInOrderTraversal {
	
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:

        void helper(TreeNode* root, std::vector<int>& res) {
            if (root == nullptr) {
                return;
            }

            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }

        std::vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> result;
            helper(root, result);
            return result;

        }
    };
 
}